/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaras <bfaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:13:03 by bfaras            #+#    #+#             */
/*   Updated: 2025/03/02 23:39:19 by bfaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

int key_handler(int keycode)
{
    if (keycode == 65307)
        exit(0);
    return (0);
}

int main ()
{
    int     fd;
    char    **map;
    char    *line;
    int     i;
    int     line_count;
    
    void *mlx_ptr;
    void *win_ptr;
    void *img_ptr;
    int width, height;

    mlx_ptr = mlx_init();

    win_ptr = mlx_new_window(mlx_ptr, 800, 600, "Eid mobark");
    img_ptr = mlx_xpm_file_to_image(mlx_ptr, "eid_fitr.xpm", &width, &height);
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
    mlx_key_hook(win_ptr, key_handler, NULL);

    // mlx_key_hook(win_ptr, key_handler, NULL);
	mlx_loop(mlx_ptr);

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
