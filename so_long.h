/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaras <bfaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:20:29 by bfaras            #+#    #+#             */
/*   Updated: 2025/03/02 15:32:02 by bfaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define PUSH_SWAP_H

#include "get_next_line/get_next_line.h"
# include <limits.h>
# include <stdint.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

char	*ft_strdup(const char *s1);
int     ft_check_characters(char **map, int line_count, int line_len);
int     ft_check_line_lengths(char **map, int line_count);
int     ft_check_horizontal_walls(char **map, int line_count, int line_len);
int     ft_check_vertical_walls(char **map, int line_count, int line_len);
int     ft_check(char **map, int line_count);

int     ft_error(void);
#endif