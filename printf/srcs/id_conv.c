/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 15:39:52 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/23 15:39:53 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static intmax_t	handle_mod_int_di(va_list *ap, t_options *flag)
{
	if (flag->modifier == j)
		return (va_arg(*ap, intmax_t));
	else if (flag->modifier == h)
		return ((short)va_arg(*ap, intmax_t));
	else if (flag->modifier == hh)
		return ((signed char)va_arg(*ap, intmax_t));
	else if (flag->modifier == l)
		return ((long)va_arg(*ap, intmax_t));
	else if (flag->modifier == ll)
		return ((long long)va_arg(*ap, intmax_t));
	else if (flag->modifier == z)
		return ((size_t)va_arg(*ap, intmax_t));
	else
		return ((int)va_arg(*ap, intmax_t));
}

void			id_conv(va_list *ap, t_options *flag)
{
	intmax_t	nbr;
	char		*prefix;

	prefix = NULL;
	nbr = handle_mod_int_di(ap, flag);
	if (nbr < 0 || flag->plus || flag->space)
	{
		if (nbr < 0)
		{
			nbr = -nbr;
			prefix = "-";
		}
		else if (flag->plus)
			prefix = "+";
		else if (flag->space)
			prefix = " ";
		else
			prefix = "";
	}
	flag_handle(flag, nbr, BASE_10, prefix);
}

void			maj_d_conv(va_list *ap, t_options *flag)
{
	flag->modifier = l;
	id_conv(ap, flag);
}
