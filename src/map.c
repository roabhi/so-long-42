/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 20:36:10 by rabril-h          #+#    #+#             */
/*   Updated: 2022/05/14 18:59:29 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../get_next_line/get_next_line.h"

char	path_is_ok(char *path)
{
	if (ft_strlen(path) < 4)
		return (0);
	return (1);
}

void fill_map_matrix(t_instance *game)
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
	// count_x = 0;
	// count_y = 0;

	// while (count_y < (int)game->map_y)
	// {
	// 	while (count_x < (int)game->map_x)
	// 	{
	// 		write(1, &game->map[count_x][count_y], 1);
	// 		count_x++;
	// 	}
	// 	count_x = 0;
	// 	count_y++;
	// 	write(1, "\n", 1);
	// }	
}

int	init_map_matrix(t_instance *game)
{
	int	count;
	
	count = 0;
	game->map = (char **)malloc(sizeof(char *) * ((game->map_x + 1)));
	if (!game->map)
		exit (EXIT_FAILURE);
	game->map[game->map_x] = NULL;
	while (count < game->map_x)
	{
		game->map[count] = malloc(sizeof(char) * ((game->map_y + 1)));
		if (!game->map[count])
			exit (EXIT_FAILURE);
		game->map[count][game->map_y] = '\0';
		count++;
	}
	return (1);
}

int	open_and_read_map(t_instance *game, char *mapsrc)
{
	char	*line;
	int		fd;
	
	if (!path_is_ok(mapsrc))
		return (0);
	fd = open(mapsrc, O_RDONLY);
	if (fd < 0)
		return (0);
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
	{
		printf("error parseando el mapa\n");
		return (0);
	}
	//Aqui irian los checqueos previos para saber si el mapa es correcto:
	//ejempl: Mapa contiene personaje y exit
	//....
	init_map_matrix(game);
	fill_map_matrix(game);
	return (1);
}
