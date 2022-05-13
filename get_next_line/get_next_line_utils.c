/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:16:05 by rabril-h          #+#    #+#             */
/*   Updated: 2022/05/12 17:29:55 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	char	*x;
	size_t	j;

	ptr = (void *)malloc(count * size);
	j = 0;
	x = (char *)ptr;
	if (!ptr)
		return (NULL);
	while (j < (count * size))
	{
		x[j] = 0;
		j++;
	}
	return ((void *)ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	c;
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlenn(s, '\0') || len == 0)
		return (ft_calloc(1, 1));
	c = ft_strlenn(s, '\0');
	if (len > c)
		len = c;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	if (len > 0)
	{
		while (i < len && s[start + i] != '\0')
		{
			str[i] = s[start + i];
			i++;
		}		
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != (unsigned char)c)
	{
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)s + i);
}

char	*ft_strdup(const char *s1)
{
	int		c;
	char	*str;

	c = 0;
	str = (char *)malloc(sizeof(char) * ft_strlenn(s1, '\0') + 1);
	if (!str)
		return (NULL);
	while (s1[c] != '\0')
	{
		str[c] = s1[c];
		c++;
	}
	str[c] = '\0';
	return ((char *)str);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*str;
	int		c;
	int		i;

	c = 0;
	i = 0;
	str = (char *)malloc(ft_strlenn(s1, '\0') + ft_strlenn(s2, '\0') + 1);
	if (!str)
		return (NULL);
	while (s1[c] != '\0')
	{
		str[c] = s1[c];
		c++;
	}
	while (s2[i] != '\0')
	{
		str[c + i] = s2[i];
		i++;
	}
	str[c + i] = '\0';
	free(s1);
	return (str);
}
