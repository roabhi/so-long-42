/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:10:25 by rabril-h          #+#    #+#             */
/*   Updated: 2022/06/02 17:10:28 by rabril-h         ###   ########.bcn      */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	setup(t_instance *game, char *mapsrc)
{
	map(game, mapsrc);
	assets(game);
	game->player.steps = 0;
	game->player.finished = '0';
	return (1);
}
