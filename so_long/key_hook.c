#include "so_long.h"

void    keyhook(mlx_key_data_t keydata, void* param, game_t game)
{
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		player_haut(&game);

	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		player_gauche(&game);

	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		player_bas(&game);

    if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
        player_droite(&game);
}

void    player_haut(game_t *game)
{
    
}

void    player_gauche(game_t *game)
{

}

void    player_bas(game_t *game)
{

}

void    player_droite(game_t *game)
{

}