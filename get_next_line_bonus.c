/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trsilva- <trsilva-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 20:48:14 by trsilva-          #+#    #+#             */
/*   Updated: 2025/03/25 23:53:31 by trsilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*fill_line(int fd, char *remains[MAX_FD])
{
	char	*line;
	char	*buffer;
	char	*temp;

	line = ft_strdup(remains[fd]);
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

char    *get_next_line(int fd) {
    static char *remains[MAX_FD];
    char        *line;

    if (fd < 0 || fd >= MAX_FD)
        return (NULL);
    if (!remains[fd])
        remains[fd] = ft_strdup("");
    line = fill_line(fd, remains);
    if (!line || !*line) {
        free(line);
        free(remains[fd]);
        remains[fd] = NULL;
        return (NULL);
    }
    free(remains[fd]);
    remains[fd] = fill_remains(line);
    return (remove_remains(line));
}


int main(void) {
    int     fd1, fd2, fd3;
    char    *line;

    fd1 = open("a.txt", O_RDONLY);
    fd2 = open("b.txt", O_RDONLY);
    fd3 = open("c.txt", O_RDONLY);

    if (fd1 < 0 || fd2 < 0 || fd3 < 0) {
        perror("Error");
        return (1);
    }
    while ((line = get_next_line(fd1))) {
        printf("File 1: %s", line);
        free(line);
    }
    printf("\n");
    while ((line = get_next_line(fd2))) {
        printf("File 2: %s", line);
        free(line);
    }
    printf("\n");
    while ((line = get_next_line(fd3))) {
        printf("File 3: %s", line);
        free(line);
    }
    printf("\n");
    close(fd1);
    close(fd2);
    close(fd3);

    return (0);
}
