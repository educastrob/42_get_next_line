/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 21:14:51 by edcastro          #+#    #+#             */
/*   Updated: 2023/06/30 00:35:50 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *) s);
		s++;
	}
	if (c == '\0')
		return ((char *) s);
	return (NULL);
}

static char	*ft_buffer_read(int fd, char *buffer)
{
	char		*temp;
	ssize_t		i;

	i = 0;
	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	while ((ft_strchr(buffer, '\n') == NULL))
	{
		i = read(fd, temp, BUFFER_SIZE);
		if (i == -1 || i == 0)
			break ;
		temp[i] = '\0';
		buffer = ft_strjoin(buffer, temp);
		if (!buffer)
		{
			free(temp);
			return (NULL);
		}
	}
	free(temp);
	if (i == -1)
		return (NULL);
	return (buffer);
}

static char	*ft_get_line(char *buffer)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!buffer)
		return (NULL);
	if (buffer[i] == '\0')
		return (NULL);
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	line = malloc((i + (buffer[i] == '\n') + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*go_to_next_line(char *buffer)
{
	char	*next;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	next = malloc((ft_strlen(buffer) - i + 1) * sizeof(char));
	if (!next)
		return (NULL);
	i++;
	while ((buffer[i]) != '\0')
		next[j++] = buffer[i++];
	next[j] = '\0';
	free(buffer);
	return (next);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_buffer_read(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_get_line(buffer);
	buffer = go_to_next_line(buffer);
	return (line);
}

// #include <stdio.h>
// #include <fcntl.h>
// #include "get_next_line.h"

// int	main()
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("texto.txt", O_RDONLY);
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s\n", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }