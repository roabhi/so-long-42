/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 20:23:57 by rabril-h          #+#    #+#             */
/*   Updated: 2022/05/11 18:00:10 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//setup - pupulate game struct
char	setup(t_instance *game, char *mapsrc)
{
	map(game, mapsrc);

	//if (!ft_readmap(game, mappath))
	//{
//		ft_putstr_fd("Error\n[FAILED TO LOAD MAP]\n", 2);
//		ft_freeall(game, 1);
//		return (0);
//	}
//	while (game->img_size * ft_strlen(game->map[0]) > 2560
//		|| game->img_size * ft_doparraysize(game->map) > 1440)
//		game->img_size /= 2;
//	if (!ft_loadimages(game))
//	{
//		ft_putstr_fd("Error\n[FAILED TO LOAD IMAGES]\n", 2);
//		ft_freeall(game, 1);
//		return (0);
//	}
	return (1);
}