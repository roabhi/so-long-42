/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:01:52 by rabril-h          #+#    #+#             */
/*   Updated: 2022/06/05 18:10:19 by rabril-h         ###   ########.bcn      */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	end_game(t_instance *game, int i)
{
	if (i == 1)
		write(1, "\nWIN", 4);
	else
		write(1, "\nLOST", 5);
	write(1, "\nYou made ", 11);
	ft_putnbr_fd(game->player.steps, 1);
	write(1, " steps", 6);
}

void	move_player(t_instance *game, int pnpx, int pnpy)
{
	mlx_put_image_to_window(game->vars.mlx, game->vars.win,
		game->imgs[3].img_ptr, pnpx * 50, pnpy * 50);
	mlx_put_image_to_window(game->vars.mlx,
		game->vars.win, game->imgs[0].img_ptr, game->player.pos_x,
		game->player.pos_y);
	game->player.pos_x = pnpx * 50;
	game->player.pos_y = pnpy * 50;
}

void	validate_move(t_instance *game, int pnpx, int pnpy)
{
	if (game->map[pnpx][pnpy] != '1'
		&& game->player.finished != '1')
	{
		game->player.steps++;
		write(1, "\nmoves:", 8);
		ft_putnbr_fd(game->player.steps, 1);
		if (game->map[pnpx][pnpy] == 'C')
		{
			if (game->player.coins > 0)
			{
				game->player.coins--;
				game->map[pnpx][pnpy] = '0';
			}			
		}
		else if (game->map[pnpx][pnpy] == 'E')
		{
			if (game->player.coins <= 0)
				end_game(game, 1);
			else
				end_game(game, 0);
			game->player.finished = '1';
		}	
		move_player(game, pnpx, pnpy);
	}
}

int	interactive(int keycode, t_instance *game)
{
	int	pnpx;
	int	pnpy;

	pnpx = game->player.pos_x / 50;
	pnpy = game->player.pos_y / 50;
	if (keycode == up)
		pnpy--;
	else if (keycode == down)
		pnpy++;
	else if (keycode == left)
		pnpx--;
	else if (keycode == right)
		pnpx++;
	else if (keycode == esc)
		destroy(game);
	else
		return (0);
	validate_move(game, pnpx, pnpy);
	return (1);
}
