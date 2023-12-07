#ifndef SO_LONG_H
#define SO_LONG_H

#include "minilibx/mlx42.h"
#include "Libft/libft.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct graph
{
    mlx_image_t *background;
    mlx_image_t *personnage;
    mlx_image_t *collect;
    mlx_image_t *walls;
    mlx_image_t *exit;
} graph_t;

typedef struct texture
{
    mlx_texture_t *background_texture;
    mlx_texture_t *personnage_texture;
    mlx_texture_t *collect_texture;
    mlx_texture_t *walls_texture;
    mlx_texture_t *exit_texture;
} texture_t;

typedef struct player
{
    int player_hauteur;
    int player_longueur;
    int nb_collect;
} player_t;

typedef struct maps
{
    unsigned int count_h;
    unsigned int count_l;
    unsigned int count_walls;
    unsigned int hauteur;
    unsigned int longueur;
    int fd;
    char **map;
    char *str;
} maps_t;

typedef struct game
{
    graph_t graph;
    texture_t texture;
    mlx_t *mlx;
    maps_t maps;
    player_t player;
} game_t;

void    lecturemap(game_t *game);
void	letter_to_png(game_t *game);
void    affiche_img(game_t *game);
void	resize_image(game_t *game);
void	texture_to_image(game_t *game);
void	load_png(game_t *game);
void    keyhook(mlx_key_data_t keydata, void* param, game_t game);

#endif