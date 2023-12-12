/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:23:33 by brclemen          #+#    #+#             */
/*   Updated: 2023/12/12 14:10:55 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx/mlx42.h"
# include "Libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct graph
{
	mlx_image_t	*background;
	mlx_image_t	*person;
	mlx_image_t	*collect;
	mlx_image_t	*walls;
	mlx_image_t	*exit;
}	t_graph;

typedef struct texture
{
	mlx_texture_t	*background_texture;
	mlx_texture_t	*person_texture;
	mlx_texture_t	*collect_texture;
	mlx_texture_t	*walls_texture;
	mlx_texture_t	*exit_texture;
}	t_texture;

typedef struct player
{
	int	player_lenght;
	int	player_height;
	int	nb_collect;
	int	moving;
}	t_player;

typedef struct maps
{
	int				count_height;
	int				count_lenght;
	int				count_walls;
	int				height;
	int				lenght;
	int				count_e;
	int				count_p;
	int				h;
	int				l;
	int				fd;
	char			**map;
	char			*str;
}	t_maps;

typedef struct game
{
	t_graph			graph;
	t_texture		texture;
	mlx_t			*mlx;
	t_maps			maps;
	t_player		player;
	int				count_c;
	size_t			exit;
}	t_game;

void	letter_to_png(t_game *game);
void	put_img(t_game *game);
void	resize_image(t_game *game);
void	texture_to_image(t_game *game);
void	load_png(t_game *game);
void	keyhook(mlx_key_data_t keydata, void *param);
void	player_up(t_game *game);
void	player_down(t_game *game);
void	player_left(t_game *game);
void	player_right(t_game *game);
void	var_ini(t_game *game);
void	collects(t_game *game, int x, int y);
void	ft_exit(t_game *game);
void	map_error(t_game *game);
void	read_map_next(t_game *game, char *str);
void	read_map(t_game *game);
void	error_rectangle(t_game *game);
void	load_letter_p(t_game *game);
void	load_letter_c(t_game *game);
void	load_letter_e(t_game *game);
void	load_letter_1(t_game *game);
void	one_all_around(t_game *game);
void	verif_close(t_game *game);

int	strlen_verif_one(char *str);
int	strlen_new_line(char *str);

#endif