#ifndef SO_LONG_H
#define SO_LONG_H

#define WIDTH 512
#define HEIGHT 512

#include "minilibx/mlx42.h"
#include <stdio.h>
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

typedef struct game
{
    graph_t graph;
    texture_t texture;
    mlx_t *mlx;
} game_t;

#endif