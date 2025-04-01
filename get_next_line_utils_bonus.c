/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trsilva- <trsilva-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 20:48:18 by trsilva-          #+#    #+#             */
/*   Updated: 2025/03/26 20:55:58 by trsilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		++i;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*dest;

	i = 0;
	j = 0;
	dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dest == NULL)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		++i;
	}
	if ((char)c == '\0')
		return ((char *)s + i);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substring;
	unsigned int	i;
	unsigned int	j;

	if (!s || start >= ft_strlen(s))
		return (malloc(1));
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	substring = malloc(sizeof(char) * (len + 1));
	if (!substring)
		return (NULL);
	i = start;
	j = 0;
	while (s[i] && j < len)
	{
		substring[j] = s[i];
		++i;
		++j;
	}
	substring[j] = '\0';
	return (substring);
}

char	*ft_strdup(const char *s)
{
	char	*new;
	int		i;

	if (!s)
		return (NULL);
	new = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!new)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		new[i] = s[i];
		++i;
	}
	new[i] = '\0';
	return (new);
}
