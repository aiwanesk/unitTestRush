/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/22 10:20:08 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/22 10:22:18 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void		ft_putnbr_base_in(uintmax_t n, size_t len_base, char *base)
{
	if (n >= len_base)
		ft_putnbr_base_in(n / len_base, len_base, base);
	ft_putchar(base[n % len_base]);
}

void			ft_putnbr_base(uintmax_t n, char *base)
{
	size_t		len_base;

	len_base = ft_strlen(base);
	if (len_base > 1)
		ft_putnbr_base_in(n, len_base, base);
}
