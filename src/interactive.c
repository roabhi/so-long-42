/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:30:47 by rabril-h          #+#    #+#             */
/*   Updated: 2022/05/18 18:50:06 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void validate_move(t_instance *game, int playerNextPosX, int playerNextPosY)   
{
    if (game->map[playerNextPosX][playerNextPosY] != '1' && game->player.finished != '1')
    {
        game->player.steps++;
        if (game->map[playerNextPosX][playerNextPosY] == 'C')
        {
            if (game->player.coins > 0)
                game->player.coins--;                     
        }else if (game->map[playerNextPosX][playerNextPosY] == 'E')
        {
            if (game->player.coins == 0)
            {
                write(1, "\nWIN", 4);
                write(1, "\nYou made these steps:",23);
                ft_putnbr_fd(game->player.steps, 1);                
            }else
            {
                write(1, "\nLOST", 5);
                write(1, "\nYou made these steps:", 23);
                ft_putnbr_fd(game->player.steps, 1);
            }
            game->player.finished = '1';
        }
        mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->imgs[3].img_ptr, playerNextPosX * 50, playerNextPosY * 50);
        mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->imgs[0].img_ptr, game->player.pos_x, game->player.pos_y);
        game->player.pos_x = playerNextPosX * 50;
        game->player.pos_y = playerNextPosY * 50;
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