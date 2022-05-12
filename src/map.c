/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 20:36:10 by rabril-h          #+#    #+#             */
/*   Updated: 2022/05/12 21:38:50 by rabril-h         ###   ########.fr       */
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
	//printf("Mi mapa es:\n%s", game->map_raw);
	printf("map cols is %d", (int)game->map_x);
	printf("map rows is %d", (int)game->map_y);
	int	count_x;
	int	count_y;
	int counter; 
	
	counter = 0;
	count_x = 0;
	count_y = 0;
	while (count_y < (int)game->map_y)
	{
		printf("\n\nMap row is %d \n\n", count_y);
		while (count_x < (int)game->map_x)
		{
			//printf("Map col is %d\n", count_cols);
			if (game->map_raw[counter] == '\n')
				counter++;
			printf("char to insert is %c <-- \n", game->map_raw[counter]);
			game->map[count_x][count_y] = game->map_raw[counter];
			//game->map[0][0] = 'D';
			printf("char inserted es %c <-- x:%d y:%d\n", game->map_raw[counter], count_x, count_y);
			counter++;
			count_x++;
		}
		count_x = 0;
		count_y++;
	}

	count_x = 0;
	count_y = 0;

	while (count_y < (int)game->map_y)
	{
		while (count_x < (int)game->map_x)
		{
			write(1, &game->map[count_x][count_y], 1);
			count_x++;
		}
		count_x = 0;
		count_y++;
		write(1, "\n", 1);
	}	
}

int	init_map_matrix(t_instance *game)
{
	int	count;
	
	count = 0;
	game->map = (char **)malloc(sizeof(char *) * ((game->map_x + 1)));
	if (!game->map)
		exit (0);
	game->map[game->map_x] = NULL;
	while (game->map[count])
	{
		game->map[count] = malloc(sizeof(char) * ((game->map_y + 1)));
		if (!game->map[count])
			exit (0);
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
	//printf("Antes if\n");
	if (line)
	{
		game->map_x = (int)ft_strlenn(line, '\n') - 1;
		while (line)
		{
			game->map_y++;
			game->map_raw = ft_strjoin(game->map_raw, line);
			//printf("while\n");
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
		exit(0);
	}
	//Aqui irian los checqueos previos para saber si el mapa es correcto:
	//ejempl: Mapa contiene personaje y exit
	//....

	//printf("Map horizontal size is %d and vertical size is %d, so total size is %d", game->map_cols, game->map_rows, game->map_cols * game->map_rows);
	init_map_matrix(game);
	fill_map_matrix(game);
	return (0);
}
