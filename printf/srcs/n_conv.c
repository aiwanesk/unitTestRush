/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 15:40:00 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/23 16:12:40 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			n_conv(va_list *ap, t_options *flag)
{
	if (flag->modifier == j)
		*va_arg(*ap, intmax_t *) = (intmax_t)flag->ret_printf;
	else if (flag->modifier == h)
		*va_arg(*ap, short *) = (short)flag->ret_printf;
	else if (flag->modifier == hh)
		*va_arg(*ap, signed char *) = (signed char)flag->ret_printf;
	else if (flag->modifier == l)
		*va_arg(*ap, long *) = (long)flag->ret_printf;
	else if (flag->modifier == ll)
		*va_arg(*ap, long long *) = (long long)flag->ret_printf;
	else if (flag->modifier == z)
		*va_arg(*ap, size_t *) = (size_t)flag->ret_printf;
	else
		*va_arg(*ap, int *) = (int)flag->ret_printf;
}
