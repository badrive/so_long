/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaras <bfaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:37:57 by bfaras            #+#    #+#             */
/*   Updated: 2024/11/29 13:59:53 by bfaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_nbr(int num)
{
	int	len;

	len = 0;
	if (num == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (len + 11);
	}
	if (num < 0)
	{
		len += write(1, "-", 1);
		num *= -1;
	}
	if (num >= 10)
	{
		len += ft_put_nbr(num / 10);
	}
	num = num % 10 + 48;
	len += write(1, &num, 1);
	return (len);
}
