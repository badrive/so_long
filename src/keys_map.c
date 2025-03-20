/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaras <bfaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:32:52 by bfaras            #+#    #+#             */
/*   Updated: 2025/03/18 15:20:31 by bfaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <X11/keysym.h>
#include <mlx.h>
#include <sys/time.h>


void	draw_black_rectangle(t_data *game, int x, int y)
{
	int i, j;
	for (i = 0; i < TILE_SIZE; i++)
	{
		for (j = 0; j < TILE_SIZE; j++)
		{
			mlx_pixel_put(game->mlx, game->win, x * TILE_SIZE + i, y * TILE_SIZE
					+ j, 0x000000);
		}
	}
}

void	exit_game(t_data *game)
{
	ft_free(game);
	exit(0);
}

void	move_player(t_data *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == '1')
		return ;
	if (game->map[new_y][new_x] == 'C')
		game->collectibles--;
	if (game->map[new_y][new_x] == 'E' && game->collectibles != 0)
		return ;
	if (game->map[new_y][new_x] == 'E' && game->collectibles == 0)
		exit_game(game);
	draw_black_rectangle(game, game->player_x, game->player_y);
	game->map[game->player_y][game->player_x] = '0';
	game->map[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
	mlx_put_image_to_window(game->mlx, game->win, game->img_player,
			game->player_x * TILE_SIZE, game->player_y * TILE_SIZE);
	game->moves++;
	printf("Moves: %d\n", game->moves);
}

int	key_handler(int keycode, t_data *game)
{
	if (keycode == XK_Escape)
		exit_game(game);
	else if (keycode == XK_w)
		move_player(game, game->player_x, game->player_y - 1);
	else if (keycode == XK_s)
		move_player(game, game->player_x, game->player_y + 1);
	else if (keycode == XK_a)
		move_player(game, game->player_x - 1, game->player_y);
	else if (keycode == XK_d)
		move_player(game, game->player_x + 1, game->player_y);
	return (0);
}
