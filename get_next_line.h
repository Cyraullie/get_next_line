/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:18:12 by cgoldens          #+#    #+#             */
/*   Updated: 2024/10/16 16:41:10 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_INE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(char *s);
#endif
