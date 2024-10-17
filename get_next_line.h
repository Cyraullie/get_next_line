/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:18:12 by cgoldens          #+#    #+#             */
/*   Updated: 2024/10/17 16:02:08 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

/*# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif*/

char	*get_next_line(int fd);
char	*ft_read_to_left_str(int fd, char *l_str);
char	*ft_get_line(char *l_str);
char	*ft_new_left_str(char *l_str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(char *s);
char	*ft_strdup(char *src);
void	*ft_memcpy(void *dest, const void *src, size_t n);
#endif
