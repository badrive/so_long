/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaras <bfaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:20:29 by bfaras            #+#    #+#             */
/*   Updated: 2025/03/16 01:53:40 by bfaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define PUSH_SWAP_H

# include "get_next_line/get_next_line.h"
# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define TILE_SIZE 64

typedef struct s_data
{
	void	*mlx;
	void	*win;
	char	**map;
	char	**map_clone;
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		flood_col;
	int		flood_ex;
	int		moves;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_collectible;
	void	*img_exit;
}			t_data;

char		*ft_strdup(const char *s1);
int			ft_check_characters(t_data *game, int line_count, int line_len);
int			ft_check_line_lengths(char **map, int line_count);
int			ft_check_horizontal_walls(char **map, int line_count, int line_len);
int			ft_check_vertical_walls(char **map, int line_count, int line_len);
int			ft_check(t_data *game, int line_count);
void		ft_fill(t_data *game);
int			key_handler(int keycode, t_data *game);
// int			update_movement(t_data *game);

int flood_fill(t_data *game, int x, int y, char **visited);
int validate_path(t_data *game);

void			ft_error(void);

#endif