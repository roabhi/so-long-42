/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 16:47:40 by rabril-h          #+#    #+#             */
/*   Updated: 2022/05/28 17:55:24 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	ft_strlenx(const char *s, char c)
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

// char	path_is_ok(char *path)
// {
// 	if (ft_strlen(path) < 4)
// 		return (0);
// 	return (1);
// }

char    map_is_rectangle(t_instance *game)
{
    int counter;
    int count_y;
    
    counter = (int)ft_strlenx(game->map[0], '\0');
	count_y = 1;
	while (count_y < (int)game->map_y)
	{
        if (counter != (int)ft_strlenx(game->map[count_y], '\0'))
            errors("Error\nMap is not a rectangle\n");
		count_y++;
	}
    return (1);
}

char	chars_are_ok(t_instance *game)
{
	int count_p;
    int count_e;
    int count_c;
    int counter;

    count_p = 0;
    count_e = 0;
    count_c = 0;
    counter = 0;
    while (game->map_raw[counter])
    {
        if (game->map_raw[counter] == 'P')
            count_p++;
        else if (game->map_raw[counter] == 'E')
            count_e++;
        else if (game->map_raw[counter] == 'C')
            count_c++;
        counter++;
    }
    if (count_p == 0 || count_e == 0 || count_c == 0)
        errors("Error\nMap is missing mandatory charts\n");
	return (1);
}

int map_validator(t_instance *game)
{
    chars_are_ok(game);
    map_is_rectangle(game);
    // if (!map_is_rectangle(game))
    // {
    //     write(1, "path is too short", 17);
    //     return (0);
    // }        
    return (1);
}