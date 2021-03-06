/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_utf8.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/22 09:44:58 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/24 15:52:46 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			count_octet(unsigned int wild_arg, size_t *ret)
{
	if (wild_arg < 0x80)
		(*ret)++;
	else if (wild_arg <= 0x7FF)
		*ret += 2;
	else if (wild_arg <= 0xFFFF)
		*ret += 3;
	else if (wild_arg <= 0x10FFFF)
		*ret += 4;
}

void			handle_wild_mask(unsigned int wild_arg)
{
	if (wild_arg < 0x80)
		ft_putchar(wild_arg);
	else if (wild_arg <= 0x7FF)
	{
		ft_putchar((wild_arg >> 6) + 0xC0);
		ft_putchar((wild_arg & 0x3F) + 0x80);
	}
	else if (wild_arg <= 0xFFFF)
	{
		ft_putchar((wild_arg >> 12) + 0xE0);
		ft_putchar(((wild_arg >> 6) & 0x3F) + 0x80);
		ft_putchar((wild_arg & 0x3F) + 0x80);
	}
	else if (wild_arg <= 0x10FFFF)
	{
		ft_putchar((wild_arg >> 18) + 0xF0);
		ft_putchar(((wild_arg >> 12) & 0x3F) + 0x80);
		ft_putchar(((wild_arg >> 6) & 0x3F) + 0x80);
		ft_putchar((wild_arg & 0x3F) + 0x80);
	}
}
