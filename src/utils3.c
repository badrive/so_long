/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaras <bfaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 23:34:02 by bfaras            #+#    #+#             */
/*   Updated: 2025/03/27 12:45:35 by bfaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <X11/X.h>
#include <mlx.h>

void	load_map(t_data *game, const char *map_file)
{
	calculate_map_height(game, map_file);
	allocate_map(game);
	read_map(game, map_file);
	validate_map_dimensions(game);
}

int	init_mlx(t_data *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->win = mlx_new_window(game->mlx, 64 * game->map_width, 64
			* game->map_height, "so_long");
	if (!game->win)
		return (0);
	return (1);
}

void	start_game(t_data *game)
{
	ft_check(game, game->map_height);
	if (!init_mlx(game))
	{
		ft_free(game);
		exit(1);
	}
	ft_fill(game);
	mlx_hook(game->win, 17, 0, exit_game, game);
	mlx_hook(game->win, KeyPress, KeyPressMask, key_handler, game);
	mlx_loop(game->mlx);
}

int	validate_args(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "ERROR\n", 6);
		return (0);
	}
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".ber", 4) != 0)
		return (write(2, "ERROR\n", 6), 0);
	return (1);
}
