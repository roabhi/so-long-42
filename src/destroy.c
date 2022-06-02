/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 16:28:08 by rabril-h          #+#    #+#             */
/*   Updated: 2022/06/02 17:11:50 by rabril-h         ###   ########.bcn      */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	free_map(t_instance *game)
{
	int		row;
	int		col;

	row = 0;
	col = 0;
	while (row < game->map_x)
	{
		free(game->map[row]);
		row++;
	}
	free(game->map[row]);
	free(game->map);
	return (0);
}

int	destroy(t_instance *game)
{
	free(game->map_raw);
	free_map(game);
	exit(-1);
}
