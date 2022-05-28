/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 20:23:57 by rabril-h          #+#    #+#             */
/*   Updated: 2022/05/28 17:44:30 by rabril-h         ###   ########.fr       */
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
