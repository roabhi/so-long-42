/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:30:47 by rabril-h          #+#    #+#             */
/*   Updated: 2022/05/16 22:45:00 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int validate_move(t_instance *game, int playerPosX, int playerPosY)   
{
    
    write(1, "player x es:", 12);
    ft_putnbr_fd(playerPosX, 1);
    write(1, "\n", 1);
    write(1, "player y es:", 12);
    ft_putnbr_fd(playerPosY, 1);    
        
    write(1, "voy al char\n", 13);
    write(1, &game->map[playerPosX][playerPosY], 1);     
    write(1, "\n", 1);
    // if (game->map[moveTo[0]][moveTo[1]] )
    //     write(1,"Can move up", 11);   
    
    return (1);
}

int    interactive(int keycode, t_instance *game)
{
    int playerPosX;
    int playerPosY;

    playerPosX = game->player.pos[0] / 50;
    playerPosY = game->player.pos[1] / 50;
    if (keycode == up)
    {
        playerPosY--;
        
    }else if(keycode == down)
    {
        playerPosY++;
    }else if(keycode == left)
    {
        playerPosX--;
    }else if(keycode == right)
    {
        playerPosX++;
    }else if(keycode == esc)
    {
        write(1, "esc\n", 4);
    }
    validate_move(game, playerPosX, playerPosY);    
    return (1);
}