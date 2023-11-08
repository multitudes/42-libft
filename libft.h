/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:45:30 by lbrusa            #+#    #+#             */
/*   Updated: 2023/11/08 12:45:52 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

int		ft_isalpha(int c);
int 	ft_isdigit(int c);
int 	ft_isalnum(int c);
int 	ft_isascii(int c);
int		ft_isprint(int c);
int		ft_strlen(const char *s);
void	*ft_memset(void *b, int c, int len);

int		ft_strncmp(const char *s1, const char *s2, int n);
void	ft_bzero(void *s, int n);


//ft_memcpy
//ft_memmove
//ft_strlcpy
//ft_strlcat
//ft_toupper
//ft_tolower
//ft_strchr
//ft_strrchr

//ft_memchr
//ft_memcmp
//ft_strnstr
//ft_atoi
//ft_calloc
//ft_strdup

#endif
