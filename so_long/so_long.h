#ifndef SO_LONG_H
#define SO_LONG_H

#define WIDTH 1024
#define HEIGHT 512

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
} graph_t;

typedef struct texture
{
    mlx_texture_t *background_texture;
    mlx_texture_t *personnage_texture;
    mlx_texture_t *collect_texture;
    mlx_texture_t *walls_texture;
} texture_t;

typedef struct maps
{
    int count_y;
    int count_x;
    int width;
    int height;
    int count_walls;
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
} game_t;

// char	open_maps_malloc(game_t *game);
// void    open_maps(game_t *game);
void    lecturemap(game_t *game);
void	letter_to_png(game_t *game);
void	png_to_img(game_t *game);

#endif