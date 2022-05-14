/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:43:20 by rabril-h          #+#    #+#             */
/*   Updated: 2022/05/14 21:14:45 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

	if (!setup(&game, params[1]))
		return (-1);	

	game.vars.mlx = mlx_init(); //This generates memory allocation
	game.vars.win = mlx_new_window(game.vars.mlx, 
		game.map_x * 50, game.map_y * 50, "I AM A PIRATE");	

	//funcion que lea el mapa, y printe en cada sitio de la pantalla el tampon que le corresponde

	printf("Llego a querer printar el mapa en pantalla");

	int count_x;
	int count_y;

	count_x = 0;
	count_y = 0;

	while (count_y < (int)game.map_y)
	{
		while (count_x < (int)game.map_x)
		{
			printf("\n");
			if (game.map[count_x][count_y] == '0')
				mlx_put_image_to_window(game.vars.mlx, game.vars.win, game.imgs[0].img_ptr, count_x * 50, count_y * 50);
				// printf("printa floor para %c en las coordernadas x:%d y:%d \n", game.map[count_x][count_y], count_x * 50, count_y * 50);
			else if (game.map[count_x][count_y] == '1')
				mlx_put_image_to_window(game.vars.mlx, game.vars.win, game.imgs[1].img_ptr, count_x * 50, count_y * 50);
				// printf("printa wall para %c en las coordernadas x:%d y:%d \n", game.map[count_x][count_y], count_x * 50, count_y * 50);
			else if (game.map[count_x][count_y] == 'C')
				mlx_put_image_to_window(game.vars.mlx, game.vars.win, game.imgs[2].img_ptr, count_x * 50, count_y * 50);
				// printf("printa collectable para %c en las coordernadas x:%d y:%d \n", game.map[count_x][count_y], count_x * 50, count_y * 50);
			else if (game.map[count_x][count_y] == 'P')
				mlx_put_image_to_window(game.vars.mlx, game.vars.win, game.imgs[3].img_ptr, count_x * 50, count_y * 50);
				// printf("printa hero para %c en las coordernadas x:%d y:%d \n", game.map[count_x][count_y], count_x * 50, count_y * 50);
			else if (game.map[count_x][count_y] == 'E')
				mlx_put_image_to_window(game.vars.mlx, game.vars.win, game.imgs[4].img_ptr, count_x * 50, count_y * 50);
				// printf("printa exit para %c en las coordernadas x:%d y:%d \n", game.map[count_x][count_y], count_x * 50, count_y * 50);
			count_x++;
		}
		count_x = 0;
		count_y++;
		write(1, "\n", 1);
	}

	// //Printo una imagen en la pantalla (poner tampon)
	//mlx_put_image_to_window(game.vars.mlx, game.vars.win, game.imgs[4].img_ptr, 50, 50);	
	mlx_loop(game.vars.mlx);
	return (0);
}
