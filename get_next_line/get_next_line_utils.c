/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurentb <laurentb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:02:47 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/30 16:12:07 by laurentb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief Extracts content from linked list nodes into a string
 * 
 * Iterates through the linked list of buffer blocks and copies all content
 * into a single string. Also tracks the position of the first newline
 * character if found.
 * 
 * @param node Pointer to the first node in the linked list
 * @param line_string The destination string to copy content into
 * @return Position of first newline character, or -1 if no newline found
 */
ssize_t	_get_content_in_lst(t_blk *node, char *line_string)
{
	ssize_t	i;
	ssize_t	pos;
	char	*content;

	i = 0;
	pos = -1;
	content = NULL;
	while (node != NULL)
	{
		content = (char *)node->content;
		while (*content != 0)
		{
			line_string[i++] = *content;
			if (pos == -1 && *content == '\n')
				pos = i ;
			content++;
		}
		node = node->next;
	}
	return (pos);
}

/**
 * @brief Extracts a line and manages remaining content
 * 
 * Builds a complete line from the linked list content. If a newline is found,
 * splits the content: returns the line up to newline and stashes the remainder
 * for the next call. Cleans up the linked list appropriately.
 * 
 * @param line Pointer to the linked list of buffer blocks
 * @param buf Buffer to free (cleanup)
 * @param n Number of bytes read in last operation
 * @return The extracted line string, or NULL if error or EOF
 * @note The caller is responsible for freeing the returned string
 */
char	*_get_line_and_stash(t_blk **line, char *buf, ssize_t n)
{
	ssize_t	pos;
	char	*line_string;
	t_blk	*node;

	free(buf);
	if ((n <= -1 && _fr(line, NULL)) || (*line == NULL))
		return (NULL);
	line_string = ft_calloc(sizeof(char), ((*line)->size + 1));
	if (line_string == NULL || (*line)->size == 0)
		return (NULL);
	pos = _get_content_in_lst(*line, line_string);
	if (pos > 0 && ((*line)->size - pos > 0))
	{
		node = _lstnew(line_string + pos, (*line)->size - pos);
		line_string[pos] = 0;
		_fr(line, NULL);
		if (!node)
			return (NULL);
		node->has_nl = _strchr_newline((char *)node->content);
		*line = node;
	}
	else
		_fr(line, NULL);
	return (line_string);
}

/**
 * @brief Frees the entire linked list and optional string
 * 
 * Traverses and frees all nodes in the linked list, including their content.
 * Also frees an optional string parameter. Sets the list pointer to NULL.
 * 
 * @param line Pointer to the linked list to free
 * @param s Optional string to free (can be NULL)
 * @return Always returns 1 for convenient error handling
 */
int	_fr(t_blk **line, char *s)
{
	t_blk	**l;
	t_blk	*tmp;

	if (*line == NULL || line == NULL)
	{
		free(s);
		return (1);
	}
	l = line;
	tmp = *line;
	while ((*line)->next != NULL)
	{
		*line = (*line)->next;
		free(tmp->content);
		free(tmp);
		tmp = *line;
	}
	free(tmp->content);
	free(tmp);
	*l = NULL;
	free(s);
	return (1);
}

/**
 * @brief Performs initial safety checks and buffer allocation
 * 
 * Validates the file descriptor and allocates the read buffer.
 * Initializes the bytes read counter to 1.
 * 
 * @param fd The file descriptor to validate
 * @param buf Pointer to buffer pointer (will be allocated)
 * @param n Pointer to bytes read counter (will be set to 1)
 * @return 1 if all checks pass and allocation succeeds, 0 otherwise
 */
int	_safety_check(int fd, char **buf, ssize_t *n)
{
	*n = 1;
	if (fd >= OPEN_MAX)
		return (0);
	*buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!*buf)
		return (0);
	return (1);
}

/**
 * @brief Reads data from file descriptor into buffer
 * 
 * Wrapper function that reads BUFFER_SIZE bytes from the file descriptor
 * into the provided buffer and updates the bytes read counter.
 * 
 * @param fd The file descriptor to read from
 * @param buf Pointer to the buffer to read into
 * @param n Pointer to store the number of bytes read
 * @return The number of bytes read (same as *n)
 */
ssize_t	read_again(int fd, char **buf, ssize_t *n)
{
	*n = read(fd, *buf, BUFFER_SIZE);
	return (*n);
}
