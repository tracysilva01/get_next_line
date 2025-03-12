/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trsilva- <trsilva-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 20:48:24 by trsilva-          #+#    #+#             */
/*   Updated: 2025/03/12 20:28:17 by trsilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h> 
#include <stdlib.h>

#ifndef BUFFER_SIZE
    #define BUFFER_SIZE 42
#endif

char    *get_next_line(int fd);
size_t  ft_strlen(const char *s);
char    *ft_strjoin(char const *s1, char const *s2);
char    *ft_strchr(const char *s, int c);
char    *ft_strdup(const char *s);
char    *ft_substr(char const *s, unsigned int start, size_t len);

#endif
