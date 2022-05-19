/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:31:02 by rabril-h          #+#    #+#             */
/*   Updated: 2022/05/18 19:34:08 by rabril-h         ###   ########.fr       */
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
	int				pos_x;
	int				pos_y;
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

enum	keys { up = 13, down = 1, left = 0, right = 2, esc = 53};

char	setup(t_instance *game, char *mapsrc);
char	map(t_instance *game, char *mapsrc);
char	assets(t_instance *game);
char	display(t_instance *game);
int		interactive(int keycode, t_instance *game);

#endif
