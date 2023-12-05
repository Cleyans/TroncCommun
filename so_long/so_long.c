#include "minilibx/mlx42.h"
#include "so_long.h"

void	png_to_img(game_t *game);

static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int32_t main(void)
{
	game_t game;

	if (!(game.mlx = mlx_init(WIDTH, HEIGHT, "So_long", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}

	lecturemap(&game);
	// open_maps_malloc(&game);
	// open_maps(&game);
	game.maps.width = game.maps.count_x *= 64;
	game.maps.height = game.maps.count_y *= 64;
	png_to_img(&game);
	letter_to_png(&game);

	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}

void	png_to_img(game_t *game)
{
	// LOAD PNG

	game->texture.background_texture = mlx_load_png("assets/decor.png"); //background
	if (!game->texture.background_texture)
		error();
	game->texture.personnage_texture = mlx_load_png("assets/pig.png"); //Perso
	if (!game->texture.personnage_texture)
		error();
	game->texture.collect_texture = mlx_load_png("assets/tomate.png"); //Collect
	if (!game->texture.collect_texture)
		error();
	game->texture.walls_texture = mlx_load_png("assets/sortie.png"); //Exit
	if (game->texture.walls_texture)

	// PNG TO TEXTURE

	game->graph.background = mlx_texture_to_image(game->mlx, game->texture.background_texture); //background
	game->graph.personnage = mlx_texture_to_image(game->mlx, game->texture.personnage_texture); //personnage
	game->graph.collect = mlx_texture_to_image(game->mlx, game->texture.collect_texture); // Collect
	game->graph.walls = mlx_texture_to_image(game->mlx, game->texture.walls_texture); //walls

	// RESIZE

	mlx_resize_image(game->graph.background, WIDTH, HEIGHT); //Background
	mlx_resize_image(game->graph.personnage, 64, 64); //Personnage
	mlx_resize_image(game->graph.collect, 64, 64); //Collect
	mlx_resize_image(game->graph.walls, 64, 64); //Walls

	// IMAGE TO WINDOWS

	mlx_image_to_window(game->mlx, game->graph.background, 0, 0); //Background
// 	mlx_image_to_window(game->mlx, game->graph.personnage, 10, 0); //Personnage
// 	mlx_image_to_window(game->mlx, game->graph.collect, 0, 10); //Collect
// 	mlx_image_to_window(game->mlx, game->graph.walls, 10, 10); //Walls
}

