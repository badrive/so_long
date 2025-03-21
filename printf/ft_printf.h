/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaras <bfaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:53:12 by bfaras            #+#    #+#             */
/*   Updated: 2024/11/29 13:34:14 by bfaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_put_str(char *str);
int	ft_put_char(int c);
int	ft_put_nbr(int num);
int	ft_put_unbr(unsigned int num);
int	ft_put_hex(unsigned long num);
int	ft_put_hex2(unsigned long num);
int	ft_put_ptr(unsigned long hex);

#endif