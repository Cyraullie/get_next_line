/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:17:59 by cgoldens          #+#    #+#             */
/*   Updated: 2024/10/17 16:13:48 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *l_str)
{
	int		i;
	char	*s;

	i = 0;
	if (!l_str)
		return (NULL);
	while (l_str[i] && l_str[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 2));
	if (!s)
	{
		free(s);
		return (NULL);
	}
	i = 0;
	while (l_str[i] && l_str[i] != '\n')
	{
		s[i] = l_str[i];
		i++;
	}
	if (l_str[i] == '\n')
	{
		s[i] = l_str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_new_left_str(char *l_str)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	if (!l_str)
	{
		free(l_str);
		return (NULL);
	}
	while (l_str[i] && l_str[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (ft_strlen(l_str) - i + 1));
	if (!s)
	{
		free(s);
		return (NULL);
	}
	i++;
	j = 0;
	while (l_str[i])
		s[j++] = l_str[i++];
	s[j] = '\0';
	free(l_str);
	return (s);
}

char	*ft_read_to_left_str(int fd, char *l_str)
{
	char	*b;
	int		rd_b;

	b = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!b)
	{
		free(b);
		return (NULL);
	}
	rd_b = 1;
	while (!ft_strchr(l_str, '\n') && rd_b != 0)
	{
		rd_b = read(fd, b, BUFFER_SIZE);
		if (rd_b == -1)
		{
			free(b);
			return (NULL);
		}
		b[rd_b] = '\0';
		l_str = ft_strjoin(l_str, b);
	}
	free(b);
	return (l_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*l_str;

	if (fd < 0 || BUFFER_SIZE <= 0 || !fd)
		return (NULL);
	if (!l_str)
		l_str = ft_strdup("");
	l_str = ft_read_to_left_str(fd, l_str);
	line = ft_get_line(l_str);
	l_str = ft_new_left_str(l_str);
	return (line);
}
/*
int	main(void)
{
	char	*line;
	int		i;
	int		fd1;

	fd1 = open("tests/test4.txt", O_RDONLY);
	printf("%d\n", fd1);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	return (0);
}
*/