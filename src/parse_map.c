/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaras <bfaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 15:41:49 by bfaras            #+#    #+#             */
/*   Updated: 2025/03/01 18:52:43 by bfaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int ft_check_characters(char **map, int line_count, int line_len)
{
    int p, e, c, i, j;

    p = 0;
    e = 0;
    c = 0;
    i = 0;
    while (i < line_count)
    {
        j = 0;
        while (j < line_len - 1)
        {
            if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'C'
                && map[i][j] != 'E' && map[i][j] != 'P')
                return (ft_error());
            if (map[i][j] == 'P')
                p++;
            if (map[i][j] == 'E')
                e++;
            if (map[i][j] == 'C')
                c++;
            j++;
        }
        i++;
    }
    if (p != 1 || e != 1 || c < 1)
        return (ft_error());
    return (0);
}

int ft_check_line_lengths(char **map, int line_count)
{
    int i;
    int expected_len;
    int current_len;

    if (line_count <= 0)
        return (ft_error());

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
            return (ft_error());
        i++;
    }
    return (0);
}

int ft_check_horizontal_walls(char **map, int line_count, int line_len)
{
    int i;

    i = 0;
    while (i < line_len - 1)
    {
        if (map[0][i] != '1' || map[line_count - 1][i] != '1')
            return (ft_error());  
        i++;
    }
    return (0);
}

int ft_check_vertical_walls(char **map, int line_count, int line_len)
{
    int i;

    i = 0;
    while (i < line_count)
    {
        if (map[i][0] != '1' || map[i][line_len - 2] != '1')
            return (ft_error());
        i++;
    }
    return (0);
}

int ft_check(char **map, int line_count)
{
    int line_len;

    if (ft_check_line_lengths(map, line_count))
        return (1);
    line_len = ft_strlen(map[0]);
    if (ft_check_horizontal_walls(map, line_count, line_len))
       return (1);  
    if (ft_check_vertical_walls(map, line_count, line_len))
        return (1);
    if (ft_check_characters(map, line_count, line_len))
        return (1);
    return (0);
}
