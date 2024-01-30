/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:03:18 by lbrusa            #+#    #+#             */
/*   Updated: 2023/12/21 19:57:39 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

typedef struct s_blk
{
	ssize_t			size;
	ssize_t			has_nl;
	void			*content;
	struct s_blk	*next;
}					t_blk;

char	*get_next_line(int fd);

char	*_get_line_and_stash(t_blk **line, char *buf, ssize_t n);
int		_freeline(t_blk **line, char *s);
ssize_t	_lst_app_str(t_blk *line, char *str, ssize_t n);
ssize_t	_strchr_newline(char *str);
t_blk	*_lstnew(void *content, ssize_t n);
int		_safe_init(char **buf, ssize_t *n);
ssize_t	read_again(int fd, char **buf, ssize_t *n);
ssize_t	_get_content_in_lst(t_blk *node, char *line_string);
void	*ft_calloc(size_t count, size_t size);

#endif
