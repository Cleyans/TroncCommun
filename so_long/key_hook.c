#include "so_long.h"

void	keyhook(mlx_key_data_t keydata, void *param)
{
    game_t *game = param;

    // if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
    //     mlx_close_window(param);

    if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
        player_haut(game);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		player_bas(game);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		player_gauche(game);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		player_droite(game);
}

void    player_haut(game_t *game)
{
	int hauteur;
    int longueur;

    hauteur = game->player.player_hauteur;
    longueur = game->player.player_longueur;
    if (game->maps.map[hauteur - 1][longueur] == '1')
        return ;
    game->graph.personnage->instances[0].y -= 64;
    game->player.player_hauteur--;
    game->player.deplacement++;
    printf("%d\n", game->player.deplacement);
	printf("collectibles : %d\n", game->count_c);
	collectibles(game, game->player.player_hauteur, longueur);
	printf("Hauteur : %d Longueur : %d\n", game->player.player_hauteur, game->player.player_longueur);
	ft_exit(game);
}

void    player_gauche(game_t *game)
{
	int hauteur;
    int longueur;

    hauteur = game->player.player_hauteur;
    longueur = game->player.player_longueur;
    if (game->maps.map[hauteur][longueur - 1] == '1')
        return ;
    game->graph.personnage->instances[0].x -= 64;
    game->player.player_longueur--;
    game->player.deplacement++;
    printf("%d\n", game->player.deplacement);
	printf("collectibles : %d\n", game->count_c);
	collectibles(game, hauteur, game->player.player_longueur);
	printf("Hauteur : %d Longueur : %d\n", game->player.player_hauteur, game->player.player_longueur);
	ft_exit(game);
}

void    player_bas(game_t *game)
{
	int hauteur;
    int longueur;

    hauteur = game->player.player_hauteur;
    longueur = game->player.player_longueur;
    if (game->maps.map[hauteur + 1][longueur] == '1')
        return ;
    game->graph.personnage->instances[0].y += 64;
    game->player.player_hauteur++;
    game->player.deplacement++;
    printf("%d\n", game->player.deplacement);
	printf("collectibles : %d\n", game->count_c);
	collectibles(game, game->player.player_hauteur, longueur);
	printf("Hauteur : %d Longueur : %d\n", game->player.player_hauteur, game->player.player_longueur);
	ft_exit(game);
}

void    player_droite(game_t *game)
{
	int hauteur;
    int longueur;

    hauteur = game->player.player_hauteur;
    longueur = game->player.player_longueur;
    if (game->maps.map[hauteur][longueur + 1] == '1')
        return ;
    game->graph.personnage->instances[0].x += 64;
    game->player.player_longueur++;
    game->player.deplacement++;
    printf("%d\n", game->player.deplacement);
	printf("collectibles : %d\n", game->count_c);
	collectibles(game, hauteur, game->player.player_longueur);
	printf("Hauteur : %d Longueur : %d\n", game->player.player_hauteur, game->player.player_longueur);
	ft_exit(game);
}