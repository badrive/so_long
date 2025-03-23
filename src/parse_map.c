/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaras <bfaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 22:51:24 by bfaras            #+#    #+#             */
/*   Updated: 2025/03/22 23:22:56 by bfaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_check(t_data *game, int line_count)
{
	int	line_len;

	ft_check_line_lengths(game, game->map, line_count);
	line_len = ft_strlen(game->map[0]);
	ft_check_horizontal_walls(game, game->map, line_count, line_len);
	ft_check_vertical_walls(game, game->map, line_count, line_len);
	ft_validate_map_characters(game, line_count, line_len);
	validate_path(game);
}
