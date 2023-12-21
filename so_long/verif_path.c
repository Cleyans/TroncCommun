// #include "so_long.h"

// static void    clone_maps(t_game *game, char **maps)
// {
//     int i;
//     int j;

//     i = 0;
//     j = 0;
//     maps = malloc(sizeof(char *) * game->maps.count_height);
//     while (game->maps.map[j])
//     {
//         while(game->maps.map[j][i])
//         {
//             maps[j][i] = game->maps.map[j][i];
//             i++;
//         }
//         j++;
//     }
// }

// static void    verif_collect(char **map, int player_height, int player_lenght, int *collect_clone)
// {
//     if (map[player_height][player_lenght] == 'C')
//         collect_clone--;
// }
// static void    verif_exit(char **map, int player_height, int player_lenght, int *exit_clone)
// {
//     if (map[player_height][player_lenght] == 'E' && exit_clone > 0)
//         exit_clone--;
// }

// void    verif_path(t_game *game)
// {
//     char **map_clone;
//     int player_height;
//     int player_lenght;
//     int collect_clone_map;
//     int exit_clone_map;

//     clone_maps(game, map_clone);
//     player_height = game->player.player_height;
//     player_lenght = game->player.player_lenght;
//     collect_clone_map = game->count_c;
//     exit_clone_map = game->exit;
//     while (1)
//     {
//         if (map_clone[player_height][player_lenght + 1] != '1')
//         {
//             player_lenght++;
//             verif_collect(map_clone, player_height, player_lenght, &collect_clone_map);
//             verif_exit(map_clone, player_height, player_lenght, &exit_clone_map);
//             map_clone[player_height][player_lenght] = '1';
//         }
//         if (map_clone[player_height + 1][player_lenght] != '1')
//         {
//             player_height++;
//             verif_collect(map_clone, player_height, player_lenght, &collect_clone_map);
//             verif_exit(map_clone, player_height, player_lenght, &exit_clone_map);
//             map_clone[player_height][player_lenght] = '1';
//         }
//         if (map_clone[player_height][player_lenght - 1] != '1')
//         {
//             player_lenght--;
//             verif_collect(map_clone, player_height, player_lenght, &collect_clone_map);
//             verif_exit(map_clone, player_height, player_lenght, &exit_clone_map);
//             map_clone[player_height][player_lenght] = '1';
//         }
//         if (map_clone[player_height - 1][player_lenght] != '1')
//         {
//             player_height--;
//             verif_collect(map_clone, player_height, player_lenght, &collect_clone_map);
//             verif_exit(map_clone, player_height, player_lenght, &exit_clone_map);
//             map_clone[player_height][player_lenght] = '1';
//         }
//         if (collect_clone_map == 0 && exit_clone_map == 'v')
//         {
//             ft_printf("The map can be played !\n");
//             free_clone_map(map_clone);
//             return ;
//         }
//         else
//         {
//             ft_printf("The map can't be played !\n");
//             free_clone_map(map_clone);
//             mlx_close_window(game->mlx);
//             return ;
//         }
//     }
	
// }

// void    free_clone_map(char **map)
// {
//     int i;
//     int j;

//     i = 0;
//     j = 0;
//     while (map[j])
//     {
//         free(map[j]);
//         j++;
//     }
//     free(map);
// }