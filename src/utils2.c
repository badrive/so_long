/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaras <bfaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 23:29:57 by bfaras            #+#    #+#             */
/*   Updated: 2025/03/22 23:41:28 by bfaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <X11/X.h>
#include <mlx.h>

void	calculate_map_height(t_data *game, const char *map_file)
{
	int		fd;
	char	*line;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		ft_exit(game);
	game->map_height = 0;
	line = get_next_line(fd);
	while (line)
	{
		game->map_height++;
		free(line);
		line = get_next_line(fd);
	}
	if (game->map_height == 0)
	{
		ft_error(game);
	}
	close(fd);
}

void	allocate_map(t_data *game)
{
	game->map = malloc(sizeof(char *) * (game->map_height + 1));
	if (!game->map)
		ft_exit(game);
	game->map_clone = malloc(sizeof(char *) * (game->map_height + 1));
	if (!game->map_clone)
		ft_exit(game);
}

int	ft_allocate_map_line(t_data *game, char *line, int i)
{
	game->map[i] = ft_strdup(line);
	game->map_clone[i] = ft_strdup(line);
	if (!game->map[i] || !game->map_clone[i])
	{
		while (i >= 0)
		{
			if (game->map[i])
				free(game->map[i]);
			if (game->map_clone[i])
				free(game->map_clone[i]);
			i--;
		}
		return (0);
	}
	return (1);
}

void	read_map(t_data *game, const char *map_file)
{
	char	*line;

	int (fd), (i);
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		ft_exit(game);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (!ft_allocate_map_line(game, line, i))
		{
			free(line);
			close(fd);
			ft_exit(game);
		}
		free(line);
		line = get_next_line(fd);
		i++;
	}
	game->map[i] = NULL;
	game->map_clone[i] = NULL;
}

void	validate_map_dimensions(t_data *game)
{
	game->map_width = ft_strlen(game->map[0]);
	if (game->map[0][game->map_width - 1] == '\n')
		game->map_width--;
	if (game->map_width <= 0 || game->map_height <= 0)
		ft_error(game);
}
