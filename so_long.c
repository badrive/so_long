/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaras <bfaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:13:03 by bfaras            #+#    #+#             */
/*   Updated: 2025/02/27 18:52:01 by bfaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main ()
{
    int     fd;
    char    **map = NULL;
    char    *line;
    int     i;
    int     line_count;

    i = 0;
    fd = open("maps/map.ber", O_RDONLY);
    line = get_next_line(fd);
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
        // printf("%s", map[i]);
        free(line);
        line = get_next_line(fd);
        i++;
    }
    map[i] = NULL;
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
