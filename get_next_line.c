/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trsilva- <trsilva-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 20:48:14 by trsilva-          #+#    #+#             */
/*   Updated: 2025/03/18 22:11:46 by trsilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *fill_line(int fd)
{
    char *buffer;
    char *temp;
    char *new_temp;
    int bytes_read;

    buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buffer)
        return (NULL);
    temp = ft_strdup("");  
    while (!ft_strchr(temp, '\n'))
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read <= 0)
        {
            free(buffer);
            if (bytes_read == 0) 
            {
                if (*temp)
                    return (temp);
                else
                {
                    free(temp);
                    return (NULL);
                }
            }
            free(temp);
            return (NULL);
        }
        buffer[bytes_read] = '\0';
        new_temp = ft_strjoin(temp, buffer);
        free(temp);
        temp = new_temp;
    }
    free(buffer);
    return (temp);
}


char *fill_remains(char *line)
{
    char *newline_pos;
    char *remains;

    newline_pos = ft_strchr(line, '\n');
    if (!newline_pos || !*(newline_pos + 1)) 
        return (NULL);
    remains = ft_strdup(newline_pos + 1);
    return (remains);
}

char *remove_remains(char *line)
{
    char *newline_pos;
    char *clean_line;

    newline_pos = ft_strchr(line, '\n');
    if (!newline_pos)
        return (line);
    clean_line = ft_substr(line, 0, newline_pos - line + 1);
    free(line);
    return (clean_line);
}

char *get_next_line(int fd)
{
    static char *remains;
    char        *line;
    char        *temp;

    if (!remains)
        remains = ft_strdup("");
    temp = fill_line(fd);
    if (!temp)
    {
        free(remains);
        remains = NULL;
        return (NULL);
    }
    line = ft_strjoin(remains, temp);
    free(temp);
    free(remains);
    remains = fill_remains(line);
    return (remove_remains(line));
}


int main(void)
{
    int fd = open("a.txt", O_RDONLY);
    char *line;

    if (fd < 0)
    {
        perror("Error opening file");
        return (1);
    }

    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return (0);
}

// gcc -g -o mi_programa get_next_line_utils.c get_next_line.c
// valgrind --leak-check=full ./mi_programa