/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned_va_arg.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/22 09:44:44 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/23 14:10:21 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t				handle_unsigned_va_arg(t_options *flag, va_list *ap)
{
	if (flag->modifier == j)
		return (va_arg(*ap, uintmax_t));
	else if (flag->modifier == h)
		return ((unsigned short)va_arg(*ap, uintmax_t));
	else if (flag->modifier == hh)
		return ((unsigned char)va_arg(*ap, uintmax_t));
	else if (flag->modifier == l)
		return ((unsigned long)va_arg(*ap, uintmax_t));
	else if (flag->modifier == ll)
		return ((unsigned long long)va_arg(*ap, uintmax_t));
	else if (flag->modifier == z)
		return ((size_t)va_arg(*ap, uintmax_t));
	else
		return ((unsigned int)va_arg(*ap, uintmax_t));
}
