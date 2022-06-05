/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:55:15 by rabril-h          #+#    #+#             */
/*   Updated: 2022/06/05 18:00:21 by rabril-h         ###   ########.bcn      */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_top_bottom(t_instance *game)
{
	int		count_y;
	int		count_x;

	count_x = 0;
	count_y = 0;
	while (count_y < (int)game->map_y)
	{
		while (count_x < (int)game->map_x)
		{
			if (count_y == 0 || count_y == (game->map_y - 1))
			{
				if (game->map[count_x][count_y] != '1')
					errors("\nERROR\nMap not rectangle");
			}
			count_x++;
		}
		count_x = 0;
		count_y++;
	}
	return (1);
}

int	check_sides(t_instance *game)
{
	int		count_y;
	int		count_x;

	count_x = 0;
	count_y = 0;
	while (count_y < (int)game->map_y)
	{
		count_x = 0;
		while (count_x < (int)game->map_x)
		{
			if (count_x == 0 || count_x == (game->map_x - 1))
			{
				if (game->map[count_x][count_y] != '1')
					errors("\nError\nMap not rectangle");
			}	
			count_x++;
		}		
		count_y++;
	}
	return (1);
}

int	paint_map(t_instance *game, int count_x, int count_y)
{
	if (game->map[count_x][count_y] == '0')
		mlx_put_image_to_window(game->vars.mlx, game->vars.win,
			game->imgs[0].img_ptr, count_x * 50, count_y * 50);
	else if (game->map[count_x][count_y] == '1')
		mlx_put_image_to_window(game->vars.mlx, game->vars.win,
			game->imgs[1].img_ptr, count_x * 50, count_y * 50);
	else if (game->map[count_x][count_y] == 'C')
	{
		game->player.coins++;
		mlx_put_image_to_window(game->vars.mlx, game->vars.win,
			game->imgs[2].img_ptr, count_x * 50, count_y * 50);
	}
	else if (game->map[count_x][count_y] == 'P')
	{
		mlx_put_image_to_window(game->vars.mlx, game->vars.win,
			game->imgs[3].img_ptr, count_x * 50, count_y * 50);
			game->player.pos_x = count_x * 50;
			game->player.pos_y = count_y * 50;
	}
	else if (game->map[count_x][count_y] == 'E')
		mlx_put_image_to_window(game->vars.mlx, game->vars.win,
			game->imgs[4].img_ptr, count_x * 50, count_y * 50);
	else
		return (0);
	return (1);
}

char	display(t_instance *game)
{
	int	count_x;
	int	count_y;

	count_x = 0;
	count_y = 0;
	check_sides(game);
	check_top_bottom(game);
	game->player.coins = 0;
	while (count_y < (int)game->map_y)
	{
		while (count_x < (int)game->map_x)
		{
			if (!paint_map(game, count_x, count_y))
				errors("\nERROR: \nMaps contains unknown char");
			count_x++;
		}
		count_x = 0;
		count_y++;
	}
	return (1);
}
