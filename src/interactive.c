/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:30:47 by rabril-h          #+#    #+#             */
/*   Updated: 2022/05/28 18:05:05 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    end_game(t_instance *game, int i)
{
    if (i == 1)
        write(1, "\nWIN", 4);
    else
        write(1, "\nLOST", 5);
    write(1, "\nYou made ", 11);
    ft_putnbr_fd(game->player.steps, 1);
    write(1, " steps", 6);
}

void validate_move(t_instance *game, int playerNextPosX, int playerNextPosY)   
{
    if (game->map[playerNextPosX][playerNextPosY] != '1' 
        && game->player.finished != '1')
    {
        game->player.steps++;
        write(1, "\nmoves:",8);
        ft_putnbr_fd(game->player.steps, 1);
        if (game->map[playerNextPosX][playerNextPosY] == 'C')
        {
            if (game->player.coins > 0)
                game->player.coins--;                     
        }else if (game->map[playerNextPosX][playerNextPosY] == 'E')
        {
            if (game->player.coins <= 0)
                end_game(game, 1); 
            else
                end_game(game, 0);
            game->player.finished = '1';
        }
        mlx_put_image_to_window(game->vars.mlx, game->vars.win, 
            game->imgs[3].img_ptr, playerNextPosX * 50, playerNextPosY * 50);
        mlx_put_image_to_window(game->vars.mlx, 
            game->vars.win, game->imgs[0].img_ptr, game->player.pos_x, 
            game->player.pos_y);
        game->player.pos_x = playerNextPosX * 50;
        game->player.pos_y = playerNextPosY * 50;
    }
}

int interactive(int keycode, t_instance *game)
{
    int playerNextPosX;
    int playerNextPosY;
    
    playerNextPosX = game->player.pos_x / 50;
    playerNextPosY = game->player.pos_y / 50;
    if (keycode == up)
            playerNextPosY--;
    else if (keycode == down)
            playerNextPosY++;
    else if (keycode == left)
            playerNextPosX--;
    else if (keycode == right)
            playerNextPosX++;
    else if (keycode == esc)
            destroy(game);
    else 
        return (0);
    validate_move(game, playerNextPosX, playerNextPosY);
    return (1);
}