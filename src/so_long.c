/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 16:21:49 by rabril-h          #+#    #+#             */
/*   Updated: 2022/06/02 17:10:12 by rabril-h         ###   ########.bcn      */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_args(int args_num, char **params)
{
	if (args_num < 2)
		errors("Error\nProvide map name and extension\n");
	if (args_num > 2)
		errors("Error\nToo many arguments.\n");
	if (ft_strnstr(params[1], ".ber", ft_strlen(params[1])) == NULL)
		errors("Error\nProvide map with .ber extension\n");
	return (1);
}

int	main(int i, char **params)
{
	t_instance	game;

	check_args(i, params);
	setup(&game, params[1]);
	game.vars.mlx = mlx_init();
	game.vars.win = mlx_new_window(game.vars.mlx,
			game.map_x * 50, game.map_y * 50, "I AM A PIRATE");
	display(&game);
	mlx_key_hook (game.vars.win, &interactive, &game);
	mlx_hook(game.vars.win, 17, 0, &destroy, &game);
	mlx_loop(game.vars.mlx);
	return (0);
}
