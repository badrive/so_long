/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaras <bfaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 23:42:37 by bfaras            #+#    #+#             */
/*   Updated: 2025/03/16 01:55:59 by bfaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int flood_fill(t_data *game, int x, int y, char **map_clone)
{
    if (x < 0 || x >= game->map_width || y < 0 || y >= game->map_height)
        return(0);
    if (map_clone[y][x] == '1' || map_clone[y][x] == 'V')
        return(0);   
    if(map_clone[y][x] == 'C')
            game->flood_col++;
    if(map_clone[y][x] == 'E')
            game->flood_ex++;
    map_clone[y][x] = 'V';
    
    // Recursively explore neighboring tiles
    flood_fill(game, x + 1, y, map_clone); // Right
    flood_fill(game, x - 1, y, map_clone); // Left
    flood_fill(game, x, y + 1, map_clone); // Down
    flood_fill(game, x, y - 1, map_clone); // Up

    return (1);
}

// Function to validate the path using flood fill
int validate_path(t_data *game)
{
    flood_fill(game, game->player_x, game->player_y, game->map_clone);
    if(game->flood_col != game->collectibles)
        return (0);
    if(game->flood_ex != 1)
        return (0);
    int i = 0;
    while (i < game->map_height)
    {
        free(game->map_clone[i]);
        i++;
    }
    free(game->map_clone);
    return (1);
}
