/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaras <bfaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 15:57:11 by bfaras            #+#    #+#             */
/*   Updated: 2025/03/22 23:42:54 by bfaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <X11/X.h>
#include <mlx.h>

void	ft_error(t_data *game)
{
	write(1, "Error\n", 6);
	ft_free(game);
	exit(1);
}

void	ft_exit(t_data *game)
{
	ft_free(game);
	exit(1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_free_mlx(t_data *game)
{
	if (game->mlx)
	{
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
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
}

void	ft_free(t_data *game)
{
	int	i;

	if (game->map)
	{
		i = 0;
		while (game->map[i])
			free(game->map[i++]);
		free(game->map);
		game->map = NULL;
	}
	if (game->map_clone)
	{
		i = 0;
		while (game->map_clone[i])
			free(game->map_clone[i++]);
		free(game->map_clone);
		game->map_clone = NULL;
	}
	ft_free_mlx(game);
	free(game);
}
