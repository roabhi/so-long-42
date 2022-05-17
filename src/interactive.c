/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:30:47 by rabril-h          #+#    #+#             */
/*   Updated: 2022/05/17 18:05:30 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void validate_move(t_instance *game, int playerNextPosX, int playerNextPosY)   
{
    
    // write(1, "player x es:", 12);
    // ft_putnbr_fd(game->player.pos_x / 50, 1);
    // write(1, "\n", 1);
    // write(1, "player y es:", 12);
    // ft_putnbr_fd(game->player.pos_y / 50, 1);    
        
    // write(1, "voy al char\n", 13);
    
    // write(1, &game->map[playerNextPosX][playerNextPosY], 1);     
    // write(1, "\n", 1);
    if (game->map[playerNextPosX][playerNextPosY] != '1')
    {
        // if (game->map[playerNextPosX][playerNextPosY] == '0')
        // {
        //     game->map[playerNextPosX][playerNextPosY] = 'P';
        //  }else if (game->map[playerNextPosX][playerNextPosY] == 'C')
        // {
        //     write(1, "coin\n", 5);
        // }else if (game->map[playerNextPosX][playerNextPosY] == 'E')
        // {
        //     write(1, "exit\n", 5);
        // }
        // game->map[playerNextPosX][playerNextPosY] = 'H';
        // game->map[game->player.pos_x][game->player.pos_y] = '0';
        // game->player.pos_x = playerNextPosX;
        // game->player.pos_y = playerNextPosY;  

        mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->imgs[3].img_ptr, playerNextPosX * 50, playerNextPosY * 50);
        mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->imgs[0].img_ptr, game->player.pos_x * 50, game->player.pos_y * 50);
        game->player.pos_x = playerNextPosX;
        game->player.pos_y = playerNextPosY; 
        
    }   

    static int count_x = 0;
	static int count_y = 0;

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

int    interactive(int keycode, t_instance *game)
{
    int playerNextPosX;
    int playerNextPosY;
    
    playerNextPosX = game->player.pos_x / 50;
    playerNextPosY = game->player.pos_y / 50;
    if (keycode == up)
    {
        playerNextPosY--;
        //playerNextPos[1]--;
        
    }else if(keycode == down)
    {
        playerNextPosY++;
        //playerNextPos[1]++;
    }else if(keycode == left)
    {
        playerNextPosX--;
        //playerNextPos[0]--;
    }else if(keycode == right)
    {
        playerNextPosX++;
        //playerNextPos[0]++;
    }else if(keycode == esc)
    {
        write(1, "esc\n", 4);
    }
    //validate_move(game, playerPosX, playerPosY);    
    validate_move(game, playerNextPosX, playerNextPosY);
    return (1);
}