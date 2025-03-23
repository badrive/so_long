/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaras <bfaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:13:03 by bfaras            #+#    #+#             */
/*   Updated: 2025/03/23 22:57:01 by bfaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <X11/X.h>
#include <mlx.h>

void	init_game(t_data *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
	game->map_clone = NULL;
	game->map_width = 0;
	game->map_height = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->collectibles = 0;
	game->flood_col = 0;
	game->flood_ex = 0;
	game->moves = 0;
	game->img_wall = NULL;
	game->img_floor = NULL;
	game->img_player = NULL;
	game->img_collectible = NULL;
	game->img_exit = NULL;
}

int	main(int ac, char **av)
{
	t_data	*game;

	if (!validate_args(ac, av))
		return (1);
	game = malloc(sizeof(t_data));
	if (!game)
		return (1);
	init_game(game);
	load_map(game, av[1]);
	start_game(game);
	ft_free(game);
	return (0);
}
