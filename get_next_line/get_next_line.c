/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:07:10 by rabril-h          #+#    #+#             */
/*   Updated: 2022/05/11 17:24:33 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../so_long.h"

size_t	ft_strlenn(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (c == '\n')
		return (i + 1);
	else
		return (i);
}

char	*clean_storage(char *storage, char *l)
{
	char	*aux;

	if (ft_strlenn(storage, '\0') == 0 && (ft_strlenn(l, '\0') == 0))
	{
		free(storage);
		return (NULL);
	}
	else
	{
		aux = ft_substr(storage, (unsigned int)ft_strlenn(storage, '\n'),
				(ft_strlenn(storage, '\0') - ft_strlenn(storage, '\n')));
		free(storage);
		return (aux);
	}	
}

char	*set_storage(int rb, char *buffer, char *storage)
{
	buffer[rb] = '\0';
	if (storage == NULL)
		return (ft_strdup(buffer));
	else
		return (ft_strjoin(storage, buffer));
}

char	*get_line(char *l)
{
	if (ft_strlenn(l, '\0') > 0)
		return (l);
	else
	{
		free (l);
		return (NULL);
	}
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*storage = NULL;
	static int	rb = 1;
	char		*buffer;

	if (fd < 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (10000 + 1));
	if (!buffer)
		return (NULL);
	while (rb > 0 && (!ft_strchr(storage, '\n')))
	{
		rb = read(fd, buffer, 10000);
		if (rb == -1 || rb == 0)
			break ;
		storage = set_storage(rb, buffer, storage);
	}	
	free(buffer);
	if (rb == -1)
		return (NULL);
	if (rb == 0 && storage == NULL)
		return (NULL);
	line = ft_substr(storage, 0, (int)ft_strlenn(storage, '\n'));
	storage = clean_storage(storage, line);
	return (get_line(line));
}
