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

/*
char *get_next_line(int fd)
{
    static char *stash;
    char        *remaining;
    // char        *buffer; pasarlo a otra subfuncion
    int         bytes_read;
    
    if (stash == NULL)
        stash = "";
   // buffer = malloc(BUFFER_SIZE + 1);
   //if (!buffer)
   //    return (0);
    while (ft_strchr(buffer, '\n') != 0)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read == -1)
            return (0);
        stash = ft_strjoin(stash, (char *)buffer);
    }
    remaining = ft_substr(stash, start, bytes_read);
    stash = ft_strchr(stash, '\n');
    return (line);
}*/

// POR AHORA SOLO LEE EL PRIMER STASH RESERVADO

char *get_next_line(int fd)
{
    static char *stash;
    char        *buffer;
    int         bytes_read;
    char        *newline;
    
    if (stash == NULL)
        stash = "";
    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return (0);
    newline = "";
    printf("A1,");
    while (newline != 0)
    {
        printf("A2\n");
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read == -1)
            return (0);
        stash = ft_strjoin(stash, (char *)buffer);
        newline = ft_strchr(buffer, '\n');  
    }
    free(buffer);
    return (stash);
}

int main (void)
{
    int fd;
    char *line;
    int  i = 0;

    fd = open("a.txt", O_RDONLY);
    while (i < 4)
    {
        line = get_next_line(fd);
        printf("%s", line);
        printf("(intento%d) \n", ++i);
    }
    return (0);
}