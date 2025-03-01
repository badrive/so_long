/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaras <bfaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:13:03 by bfaras            #+#    #+#             */
/*   Updated: 2025/03/01 23:56:12 by bfaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

int main ()
{
    int     fd;
    char    **map;
    char    *line;
    int     i;
    int     line_count;
    void	*mlx_ptr;
    void	*mlx;

    mlx = mlx_init();
    mlx_ptr = mlx_new_window(mlx, 800, 600, "Hello, MLX!");
    mlx_loop(mlx);

    fd = open("maps/map.ber", O_RDONLY);
    map = NULL;
    line = get_next_line(fd);
    i = 0;
    line_count = 0;
    while (line)
    {
        line_count++;
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    map = malloc(sizeof(char *) * (line_count + 1));
    if (!map)
        return (1);

    fd = open("maps/map.ber", O_RDONLY);
    i = 0;
    line = get_next_line(fd);
    while (line)
    {
        map[i] = ft_strdup(line);    
        free(line);
        line = get_next_line(fd);
        i++;
    }
    map[i] = NULL;
    ft_check(map,line_count);
    close(fd);

    i = 0;
    while (map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);

    return (0);
}
