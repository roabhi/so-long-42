/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:44:31 by rabril-h          #+#    #+#             */
/*   Updated: 2022/06/02 17:38:41 by rabril-h         ###   ########.bcn      */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*get_img_path(int index, char *path)
{
	if (index == 0)
		path = "images/floor.xpm";
	else if (index == 1)
		path = "images/wall.xpm";
	else if (index == 2)
		path = "images/collectable.xpm";
	else if (index == 3)
		path = "images/hero.xpm";
	else if (index == 4)
		path = "images/exit.xpm";
	return (path);
}

char	load_img(t_instance *game, int index)
{
	int		height;
	int		width;
	char	*path;

	path = NULL;
	game->imgs[index].img_ptr = mlx_xpm_file_to_image(game->vars.mlx,
			get_img_path(index, path), &width, &height);
	if (!game->imgs[index].img_ptr)
		errors("Error loading image \n");
	game->imgs[index].addr
		= (int *)mlx_get_data_addr(game->imgs[index].img_ptr,
			&game->imgs[index].bits_per_pixel, &game->imgs[index].line_length,
			&game->imgs[index].endian);
	if (!game->imgs[index].addr)
		errors("Error loading image \n");
	return (1);
}

char	assets(t_instance *game)
{
	int	count;

	count = 0;
	while (count < 5)
	{
		if (!load_img(game, count))
			return (-1);
		count++;
	}
	return (1);
}
