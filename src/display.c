/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:55:15 by rabril-h          #+#    #+#             */
/*   Updated: 2022/05/16 20:29:22 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char    display(t_instance *game)
{
	int count_x;
	int count_y;

	count_x = 0;
	count_y = 0;
	while (count_y < (int)game->map_y)
	{
		while (count_x < (int)game->map_x)
		{
			//printf("\n");
			if (game->map[count_x][count_y] == '0')
            {
                mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->imgs[0].img_ptr, count_x * 50, count_y * 50);
				// printf("printa floor para %c en las coordernadas x:%d y:%d \n", game->map[count_x][count_y], count_x * 50, count_y * 50);
            }else if (game->map[count_x][count_y] == '1')
            {
                mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->imgs[1].img_ptr, count_x * 50, count_y * 50);
				// printf("printa wall para %c en las coordernadas x:%d y:%d \n", game->map[count_x][count_y], count_x * 50, count_y * 50);
            }else if (game->map[count_x][count_y] == 'C')
            {
                mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->imgs[2].img_ptr, count_x * 50, count_y * 50);
				// printf("printa collectable para %c en las coordernadas x:%d y:%d \n", game->map[count_x][count_y], count_x * 50, count_y * 50);
            }else if (game->map[count_x][count_y] == 'P')
            {
                mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->imgs[3].img_ptr, count_x * 50, count_y * 50);
                game->player.pos[0] = count_x * 50;
                game->player.pos[1] = count_y * 50;                
				// printf("printa hero para %c en las coordernadas x:%d y:%d \n", game->map[count_x][count_y], count_x * 50, count_y * 50);
            }else if (game->map[count_x][count_y] == 'E')
            {
                mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->imgs[4].img_ptr, count_x * 50, count_y * 50);
				// printf("printa exit para %c en las coordernadas x:%d y:%d \n", game->map[count_x][count_y], count_x * 50, count_y * 50);
            }				
			count_x++;
		}
		count_x = 0;
		count_y++;
	}

    

    return (1);
}