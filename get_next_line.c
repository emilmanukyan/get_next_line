/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:30:02 by emanukya          #+#    #+#             */
/*   Updated: 2024/03/03 16:23:45 by emanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	get_line(char *buffer, char **line)
{
	int		i;
	int		j;
	int		line_exist;
	char	*newline;

	i = 0;
	j = 0;
	line_exist = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		line_exist = 1;
	newline = ft_calloc(i + line_exist + 1, sizeof(char));
	if (newline == NULL)
		return (-1);
	while (j < i + line_exist)
	{
		newline[j] = buffer[j];
		j++;
	}
	*line = ft_strjoin(*line, newline);
	if (line == NULL)
		return (-1);
	ft_strcpy(buffer, &buffer[i + line_exist]);
	return (line_exist);
}

static char	*free_line(char **line)
{
	if (*line != NULL)
		free(*line);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;
	int			line_exist;

	line = NULL;
	line_exist = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	while (line_exist == 0)
	{
		line_exist = get_line(buffer, &line);
		if (line_exist == -1)
			return (free_line(&line));
		if (line_exist == 0)
		{
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			if (bytes_read == 0 && *line)
				line_exist = 1;
			else if (bytes_read <= 0)
				return (free_line(&line));
			buffer[bytes_read] = '\0';
		}
	}
	return (line);
}
/*#include <fcntl.h>
#include <stdio.h>
int main()
{
	int fd = open("PATH_TO_FILE", O_RDWR);
	printf("%s", get_next_line(fd));
 	printf("%s", get_next_line(fd));
}*/
