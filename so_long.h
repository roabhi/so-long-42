/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:31:02 by rabril-h          #+#    #+#             */
/*   Updated: 2022/05/13 21:28:48 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# include "libft/libft.h"
# include "minilibx/mlx.h"

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;


typedef struct s_img
{
	void	*img_ptr;
	int		img_width;
	int		img_height;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_player
{
	unsigned int	coins;
	unsigned int	steps;
	int				pos[2];
	char			finished;
}	t_player;

typedef struct s_instance
{
	t_img		imgs[5];
	int			img_size;
	t_vars		vars;
	t_player	player;
	char		**map;
	char		*map_raw;
	int			map_y;
	int			map_x;
}	t_instance;

char	setup(t_instance *game, char *mapsrc);
char	map(t_instance *game, char *mapsrc);

#endif
