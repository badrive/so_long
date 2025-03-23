/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaras <bfaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 15:41:49 by bfaras            #+#    #+#             */
/*   Updated: 2025/03/22 22:52:09 by bfaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_count_map_elements(t_data *game, int line_count, int line_len)
{
	int (p), (e), (c), (i), (j);
	p = 0;
	e = 0;
	c = 0;
	i = 0;
	while (i < line_count)
	{
		j = 0;
		while (j < line_len - 1)
		{
			if (game->map[i][j] == 'P')
				p++;
			if (game->map[i][j] == 'E')
				e++;
			if (game->map[i][j] == 'C')
			{
				c++;
				game->collectibles++;
			}
			j++;
		}
		i++;
	}
	if (p != 1 || e != 1 || c < 1)
		ft_error(game);
}

void	ft_validate_map_characters(t_data *game, int line_count, int line_len)
{
	int (i), (j);
	i = 0;
	game->moves = 0;
	game->collectibles = 0;
	while (i < line_count)
	{
		j = 0;
		while (j < line_len - 1)
		{
			if (game->map[i][j] != '1' && game->map[i][j] != '0'
				&& game->map[i][j] != 'C' && game->map[i][j] != 'E'
				&& game->map[i][j] != 'P')
				ft_error(game);
			if (game->map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
			}
			j++;
		}
		i++;
	}
	ft_count_map_elements(game, line_count, line_len);
}

void	ft_check_line_lengths(t_data *game, char **map, int line_count)
{
	int	i;
	int	expected_len;
	int	current_len;

	if (line_count <= 0)
		ft_error(game);
	expected_len = ft_strlen(map[0]);
	if (map[0][expected_len - 1] == '\n')
		expected_len--;
	i = 0;
	while (i < line_count)
	{
		current_len = ft_strlen(map[i]);
		if (map[i][current_len - 1] == '\n')
			current_len--;
		if (current_len != expected_len)
			ft_error(game);
		i++;
	}
}

void	ft_check_horizontal_walls(t_data *game, char **map, int line_count,
		int line_len)
{
	int	i;

	i = 0;
	while (i < line_len - 1)
	{
		if (map[0][i] != '1' || map[line_count - 1][i] != '1')
			ft_error(game);
		i++;
	}
}

void	ft_check_vertical_walls(t_data *game, char **map, int line_count,
		int line_len)
{
	int	i;

	i = 0;
	while (i < line_count)
	{
		if (map[i][0] != '1' || map[i][line_len - 2] != '1')
			ft_error(game);
		i++;
	}
}
