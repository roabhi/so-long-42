/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:43:20 by rabril-h          #+#    #+#             */
/*   Updated: 2022/05/13 18:59:41 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
//#include "setup.c"

int	check_args(int args_num, char **params)
{
	if (args_num < 2)
	{
		ft_putstr_fd("Provide map name and extension as argument\n Ex: ./so_long maps/map.ber \n",2);
		exit(EXIT_FAILURE);
	}
	if (args_num > 2)
	{
		ft_putstr_fd("Too many arguments. Provide only map name and extension\n Ex: ./so_long maps/map.ber \n",2);
		exit(EXIT_FAILURE);
	}		
	if (ft_strnstr(params[1], ".ber", ft_strlen(params[1])) == NULL)
	{
		ft_putstr_fd("Invalid map extension. Use .ber \n",2);
		exit(EXIT_FAILURE);
	}		
	return (0);
}

int	main(int i, char **params)
{
	t_instance	game;

	check_args(i, params);
	game.vars.mlx = mlx_init(); //This generates memory allocation
	if (!setup(&game, params[1]))
		return (-1);
	game.vars.win = mlx_new_window(game.vars.mlx, 640, 360, "MATA NEURONAS");
	mlx_loop(game.vars.mlx);
	return (0);
}
