/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 20:36:10 by rabril-h          #+#    #+#             */
/*   Updated: 2022/05/28 18:40:05 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../get_next_line/get_next_line.h"

void	fill_map_matrix(t_instance *game)
{
	int	count_x;
	int	count_y;
	int	counter;

	counter = 0;
	count_x = 0;
	count_y = 0;
	while (count_y < (int)game->map_y)
	{
		while (count_x < (int)game->map_x)
		{
			if (game->map_raw[counter] == '\n')
				counter++;
			game->map[count_x][count_y] = game->map_raw[counter];
			counter++;
			count_x++;
		}
		count_x = 0;
		count_y++;
	}
}

int	init_map_matrix(t_instance *game)
{
	int	count;

	count = 0;
	game->map = (char **)malloc(sizeof(char *) * ((game->map_x + 1)));
	if (!game->map)
		errors("Error\nCould not allocate memory\n");
	game->map[game->map_x] = NULL;
	while (count < game->map_x)
	{
		game->map[count] = malloc(sizeof(char) * ((game->map_y + 1)));
		if (!game->map[count])
			errors("Error\nCould not allocate memory\n");
		game->map[count][game->map_y] = '\0';
		count++;
	}
	return (1);
}

int	open_and_read_map(t_instance *game, char *mapsrc)
{
	char	*line;
	int		fd;

	fd = open(mapsrc, O_RDONLY);
	if (fd < 0)
		errors("Error\nCould not read map\n");
	line = get_next_line(fd);
	if (line)
	{
		game->map_x = (int)ft_strlenn(line, '\n') - 1;
		while (line)
		{
			game->map_y++;
			game->map_raw = ft_strjoin(game->map_raw, line);
			free(line);
			line = get_next_line(fd);
		}
		free(line);
	}
	close(fd);
	return (1);
}

char	map(t_instance *game, char *mapsrc)
{
	game->map_x = 0;
	game->map_y = 0;
	if (!open_and_read_map(game, mapsrc))
		errors("Error\nCould not read map\n");
	init_map_matrix(game);
	fill_map_matrix(game);
	map_validator(game);
	return (1);
}
