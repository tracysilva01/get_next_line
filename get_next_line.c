/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trsilva- <trsilva-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 20:48:14 by trsilva-          #+#    #+#             */
/*   Updated: 2025/03/12 20:22:00 by trsilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE 5

char *get_next_line(int fd)
{
    static char *stash;
    char        *line;
    char        *buffer;
    int         bytes_read;
    
    if (stash == NULL)
        stash = "";
    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return (0);
    while (ft_strchr(buffer, '\n') == 0)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read == -1)
            return (0);
        stash = ft_strjoin(stash, (char *)buffer);
    }
    line = ft_substr(stash, start, bytes_read);
    stash = ft_strchr(stash, '\n');
    return (line);
}

char *get_next_line(int fd)
{
    char    *line;
    char    *buffer;
    
    buffer = malloc(BUFFER_SIZE + 1);
    line = read(fd, buffer, sizeof(buffer));
    
    return (line);
}

