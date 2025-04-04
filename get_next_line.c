/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trsilva- <trsilva-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 20:48:14 by trsilva-          #+#    #+#             */
/*   Updated: 2025/04/01 18:29:34 by trsilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_and_store(int fd)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(buffer);
		if (bytes_read == 0)
			return (NULL);
		return (NULL);
	}
	buffer[bytes_read] = '\0';
	return (buffer);
}

char	*fill_line(int fd, char *remains)
{
	char	*line;
	char	*buffer;
	char	*temp;

	line = ft_strdup(remains);
	while (!ft_strchr(line, '\n'))
	{
		buffer = read_and_store(fd);
		if (!buffer)
			break ;
		temp = ft_strjoin(line, buffer);
		free(line);
		free(buffer);
		line = temp;
	}
	return (line);
}

char	*fill_remains(char *line)
{
	char	*newline_pos;
	char	*remains;

	newline_pos = ft_strchr(line, '\n');
	if (!newline_pos || !*(newline_pos + 1))
		return (NULL);
	remains = ft_strdup(newline_pos + 1);
	return (remains);
}

char	*remove_remains(char *line)
{
	char	*newline_pos;
	char	*clean_line;

	newline_pos = ft_strchr(line, '\n');
	if (!newline_pos)
		return (line);
	clean_line = ft_substr(line, 0, newline_pos - line + 1);
	free(line);
	return (clean_line);
}

char	*get_next_line(int fd)
{
	static char	*remains;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!remains)
		remains = ft_strdup("");
	line = fill_line(fd, remains);
	if (!line || !*line)
	{
		free(line);
		free(remains);
		remains = NULL;
		return (NULL);
	}
	free(remains);
	remains = fill_remains(line);
	return (remove_remains(line));
}


int	main(void)
{
	int		fd;
	char	*line;

	fd = open("archivo.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (0);
}
