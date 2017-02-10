/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 15:40:27 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/23 18:49:08 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			x_conv(va_list *ap, t_options *flag)
{
	char		*prefix;
	uintmax_t	nbr;

	nbr = apply_modifier(flag, ap);
	flag->sep = 0;
	prefix = flag->hash && !(flag->hash && !nbr) ? "0x" : NULL;
	flag_handle(flag, nbr, BASE_16_L, prefix);
}

void			maj_x_conv(va_list *ap, t_options *flag)
{
	char		*prefix;
	uintmax_t	nbr;

	nbr = apply_modifier(flag, ap);
	flag->sep = 0;
	prefix = flag->hash && !(flag->hash && !nbr) ? "0X" : NULL;
	flag_handle(flag, nbr, BASE_16_U, prefix);
}
