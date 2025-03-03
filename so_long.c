/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaras <bfaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:13:03 by bfaras            #+#    #+#             */
/*   Updated: 2025/03/03 17:13:32 by bfaras           ###   ########.fr       */
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
    int     j;

    void *mlx_ptr;
    void *win_ptr;
    void *img_ptr;
    int width, height;

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
    // checker
    ft_check(map,line_count);
    //
    // create the map
    int len  = ft_strlen(map[0]) - 1;
    mlx_ptr = mlx_init();
    i = 0;
    j = 0;
    win_ptr = mlx_new_window(mlx_ptr, 64 * len, line_count * 64, "so_long");

    while (i < line_count)
    {
        j = 0;
        while (j < len)
        {
            if (map[i][j] == '1')
            {
                img_ptr = mlx_xpm_file_to_image(mlx_ptr, "textures/stone.xpm", &width, &height);
                mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, j * 64, i * 64);           
            }
            else if (map[i][j] == '0')
            {
                img_ptr = mlx_xpm_file_to_image(mlx_ptr, "textures/dirty.xpm", &width, &height);
                mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, j * 64, i * 64);           
            }
            else if (map[i][j] == 'P')
            {
                img_ptr = mlx_xpm_file_to_image(mlx_ptr, "textures/sonic.xpm", &width, &height);
                mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, j * 64, i * 64);           
            }
            else if (map[i][j] == 'C')
            {
                img_ptr = mlx_xpm_file_to_image(mlx_ptr, "textures/coin.xpm", &width, &height);
                mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, j * 64, i * 64);           
            }
            else if (map[i][j] == 'E')
            {
                img_ptr = mlx_xpm_file_to_image(mlx_ptr, "textures/exit.xpm", &width, &height);
                mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, j * 64, i * 64);           
            }
            j++;
        }
        i++;
    }

    mlx_key_hook(win_ptr, key_handler, NULL);
	mlx_loop(mlx_ptr);
    //
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
