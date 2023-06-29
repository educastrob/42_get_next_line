/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 21:14:51 by edcastro          #+#    #+#             */
/*   Updated: 2023/06/15 13:40:42 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_buffer_read(int fd, char *buffer)
{
	char	*temp;
	int 	i;
	
	i = 0;
	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (temp == NULL)
		return (NULL);
	while ((ft_strchr(buffer, '\n') == NULL))
	{
		i = read(fd, temp, BUFFER_SIZE);
		if (i == -1 || i == 0)
			break ;
		temp[i] = '\0';
		buffer = ft_strjoin(buffer, temp);
		if (buffer == NULL)
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
	{
		line[i] = '\n';
		i++;
	}
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
	if (next == NULL)
		return (NULL);
	i++;
	while ((buffer[i + j]) != '\0')
	{
		next[j] = buffer[i + j];
		j++;
	}
	free(buffer);
	return (next);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = ft_buffer_read(fd, buf);
	if (buf == NULL)
		return (NULL);
	line = ft_get_line(buf);
	buf = go_to_next_line(buf);
	return (line);
}

// #include <stdio.h>
// #include <fcntl.h>
// int main(int argc, char *argv[])
// {
//     int fd;
//     char *line;
    
//     if (argc != 2)
//         return (0);
//     fd = open(argv[1], O_RDONLY);
//     if (fd < 0)
//         return (-1);


//     line = get_next_line(fd);
//     printf("fd: %s", line);
//     free(line);
    
//     line = get_next_line(fd);
//     printf("fd: %s", line);
//     free(line);
    
//     line = get_next_line(fd);
//     printf("fd: %s", line);
//     free(line);

//     line = get_next_line(fd);
//     printf("fd: %s", line);
//     free(line);

//     line = get_next_line(fd);
//     printf("fd: %s", line);
//     free(line);
//     while (i <= 30)
//     {
//         printf("%d - %s", i, line);
//          free(line);
//         if (line == NULL)
//             printf("\n");
//         line = get_next_line(fd);
//         i++;
//     }
//     close(fd);
// }