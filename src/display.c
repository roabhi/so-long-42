/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:55:15 by rabril-h          #+#    #+#             */
/*   Updated: 2022/05/19 19:51:26 by rabril-h         ###   ########.fr       */
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
				{
					ft_putstr_fd("\n Map bottom or top have errors\n", 1);
					//write(1, &game->map[count_x][count_y], 1);
					return (0);
				}	
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
				{
					ft_putstr_fd("\n Map sides have errors\n", 1);
					//write(1, &game->map[count_x][count_y], 1);
					return (0);
				}				
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
	write(1, "\n", 1);
	if (!check_sides(game))
		return (0);
	if (!check_top_bottom(game))
		return (0);
	while (count_y < (int)game->map_y)
	{
		while (count_x < (int)game->map_x)
		{
			if (!paint_map(game, count_x, count_y))
			{
				write(1, "\nERROR: \nMaps contains unknown char", 37);
				return (0);
			}				
			count_x++;
		}
		count_x = 0;
		count_y++;
	}
	return (1);
}