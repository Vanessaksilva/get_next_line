/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:22:55 by coder             #+#    #+#             */
/*   Updated: 2022/05/26 01:04:14 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
		return (ft_strlen(src));
	while (src[i] && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

static char	*get_line(char	*str)
{
	char	*line;
	size_t	size;

	if (!*str)
		return (NULL);
	size = 0;
	while (str[size] && str[size] != '\n')
		size++;
	line = (char *)malloc(sizeof(char) * (size + 2));
	if (!line)
		return (NULL);
	ft_strlcpy(line, str, size + 1);
	if (str[size] == '\n')
		line[size++] = '\n';
	line[size] = '\0';
	return (line);
}

static char	*get_to_next(char	*str)
{
	char	*result;
	int		i;
	int		j;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i] || !str[i + 1])
		return (free(str), NULL);
	if (str[i])
		i++;
	result = malloc(sizeof(char) * ft_strlen(str + i) + 1);
	if (result == NULL)
		return (free(str), NULL);
	j = 0;
	while (str[i])
		result[j++] = str[i++];
	result[j] = '\0';
	free(str);
	return (result);
}

static char	*read_file(int fd, char *s)
{
	char	*buff;
	int		readed;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	readed = 1;
	while ((ft_strchr(s, '\n') == NULL) && readed != 0)
	{
		readed = read(fd, buff, BUFFER_SIZE);
		if (readed <= 0)
			break ;
		buff[readed] = '\0';
		s = ft_strjoin(s, buff);
	}
	free(buff);
	if (readed < 0)
		return (NULL);
	else
		return (s);
}

char	*get_next_line(int fd)
{
	static char	*s[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > OPEN_MAX)
		return (NULL);
	s[fd] = read_file(fd, s[fd]);
	if (!s[fd])
		return (NULL);
	line = get_line(s[fd]);
	s[fd] = get_to_next(s[fd]);
	return (line);
}

//MAIN
/* #include <fcntl.h>
#include <stdio.h>
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test0.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf("%s", line);
		if (line == NULL)
			break ;
		free(line);
	}
	return (0);
}  */
