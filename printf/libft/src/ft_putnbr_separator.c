/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_separator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/22 10:26:36 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/23 18:50:05 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void		ft_putnbr_separator_rec(uintmax_t n, char *sep,
		size_t i, size_t len)
{
	i++;
	if (n > 9)
		ft_putnbr_separator_rec(n / 10, sep, i, len);
	if (!(i % 3) && i != len)
		ft_putstr(sep);
	ft_putchar(48 + (n % 10));
}

void			ft_putnbr_separator(uintmax_t n, char *sep)
{
	size_t		i;
	size_t		len;

	i = 0;
	len = ft_nlen(n, 10);
	ft_putnbr_separator_rec(n, sep, i, len);
}
