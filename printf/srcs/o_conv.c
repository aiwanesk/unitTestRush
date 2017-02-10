/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 15:39:37 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/23 15:39:37 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			o_conv(va_list *ap, t_options *flag)
{
	uintmax_t	nbr;
	size_t		len;

	flag->sep = 0;
	nbr = apply_modifier(flag, ap);
	len = ft_nlen(nbr, 8);
	if (flag->hash && !nbr && flag->got_prec && !flag->prec)
	{
		handle_trial_prec('0', flag);
		return ;
	}
	else if (flag->hash && nbr)
	{
		flag->got_prec = 1;
		if (flag->prec <= (int)len)
			flag->prec = len + 1;
	}
	flag_handle(flag, nbr, BASE_8, NULL);
}

void			maj_o_conv(va_list *ap, t_options *flag)
{
	flag->modifier = l;
	o_conv(ap, flag);
}
