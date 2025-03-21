/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaras <bfaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:03:48 by bfaras            #+#    #+#             */
/*   Updated: 2025/03/20 23:43:33 by bfaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <mlx.h>

void ft_fill(t_data *game)
{
    int i;
    int j;
    int width, height;

    i = 0;
    j = 0;

    if (game->img_wall)
        mlx_destroy_image(game->mlx, game->img_wall);
    if (game->img_floor)
        mlx_destroy_image(game->mlx, game->img_floor);
    if (game->img_player)
        mlx_destroy_image(game->mlx, game->img_player);
    if (game->img_collectible)
        mlx_destroy_image(game->mlx, game->img_collectible);
    if (game->img_exit)
        mlx_destroy_image(game->mlx, game->img_exit);

    game->img_wall = mlx_xpm_file_to_image(game->mlx, "textures/stone.xpm", &width, &height);
    game->img_player = mlx_xpm_file_to_image(game->mlx, "textures/sonic.xpm", &width, &height);
    game->img_collectible = mlx_xpm_file_to_image(game->mlx, "textures/coin.xpm", &width, &height);
    game->img_exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &width, &height);
    if(!game->img_wall||!game->img_player||!game->img_collectible||!game->img_exit)
        {
            ft_free(game);
            exit(1);
        }
    while (i < game->map_height)
    {
        j = 0;
        while (j < game->map_width)
        {
            if (game->map[i][j] == '1')
                mlx_put_image_to_window(game->mlx, game->win, game->img_wall, j * 64, i * 64);
            else if (game->map[i][j] == 'P')
                mlx_put_image_to_window(game->mlx, game->win, game->img_player, j * 64, i * 64);
            else if (game->map[i][j] == 'C')
                mlx_put_image_to_window(game->mlx, game->win, game->img_collectible, j * 64, i * 64);
            else if (game->map[i][j] == 'E')
                mlx_put_image_to_window(game->mlx, game->win, game->img_exit, j * 64, i * 64);
            j++;
        }
        i++;
    }
}
