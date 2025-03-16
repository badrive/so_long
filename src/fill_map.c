/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaras <bfaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:03:48 by bfaras            #+#    #+#             */
/*   Updated: 2025/03/07 23:43:20 by bfaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <mlx.h>

void	ft_fill(t_data *game)
{
	int	i;
	int	j;

	int width, height;
	i = 0;
	j = 0;
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "textures/stone.xpm",
			&width, &height);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "textures/sonic.xpm",
			&width, &height);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx,
			"textures/coin.xpm", &width, &height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm",
			&width, &height);
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->img_wall, j
						* 64, i * 64);
			else if (game->map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->img_player,
						j * 64, i * 64);
			else if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win,
						game->img_collectible, j * 64, i * 64);
			else if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->img_exit, j
						* 64, i * 64);
			j++;
		}
		i++;
	}
}
