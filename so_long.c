/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaras <bfaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:13:03 by bfaras            #+#    #+#             */
/*   Updated: 2025/03/16 01:53:57 by bfaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <X11/X.h>
#include <mlx.h>

void	ft_free(t_data *game)
{
	int	i;

	if (game->map)
	{
		i = 0;
		while (game->map[i])
			free(game->map[i++]);
		free(game->map);
	}
	if (game->mlx && game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		free(game->mlx);
	free(game);
}

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
	game->img_player = NULL;
	game->img_collectible = NULL;
	game->img_exit = NULL;
}

int	calculate_map_height(t_data *game, const char *map_file)
{
	int		fd;
	char	*line;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (0);
	game->map_height = 0;
	while ((line = get_next_line(fd)))
	{
		game->map_height++;
		free(line);
	}
	close(fd);
	return (1);
}

int	allocate_map(t_data *game)
{
	game->map = malloc(sizeof(char *) * (game->map_height + 1));
	if (!game->map)
		return (0);
	game->map_clone = malloc(sizeof(char *) * (game->map_height + 1));
	if (!game->map_clone)
		return (0);
	return (1);
}

int	read_map(t_data *game, const char *map_file)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (0);
	i = 0;
	while ((line = get_next_line(fd)))
	{
		game->map[i] = ft_strdup(line);
		game->map_clone[i] = ft_strdup(line);
		free(line);
		i++;
	}
	game->map[i] = NULL;
	game->map_clone[i] = NULL;
	close(fd);
	return (1);
}

int	validate_map_dimensions(t_data *game)
{
	game->map_width = strlen(game->map[0]);
	if (game->map[0][game->map_width - 1] == '\n')
		game->map_width--;
	if (game->map_width <= 0 || game->map_height <= 0)
	{
		fprintf(stderr, "Error: Invalid map dimensions\n");
		return (0);
	}
	return (1);
}

int	load_map(t_data *game, const char *map_file)
{
	if (!calculate_map_height(game, map_file))
		return (0);
	if (!allocate_map(game))
		return (0);
	if (!read_map(game, map_file))
		return (0);
	if (!validate_map_dimensions(game))
		return (0);
	return (1);
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
	ft_fill(game);
	mlx_hook(game->win, KeyPress, KeyPressMask, key_handler, game);
	mlx_loop(game->mlx);
}

int	validate_args(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "ARG_ERROR\n", 11);
		return (0);
	}
	if (strncmp(av[1] + strlen(av[1]) - 4, ".ber", 4) != 0)
		return (0);
	return (1);
}

int	setup_game(t_data *game, const char *map_file)
{
	if (!load_map(game, map_file))
		return (0);
	if (!init_mlx(game))
		return (0);
	return (1);
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
	if (!setup_game(game, av[1]))
	{
		ft_free(game);
		return (1);
	}
	start_game(game);
	ft_free(game);
	return (0);
}
