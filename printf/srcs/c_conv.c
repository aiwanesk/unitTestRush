/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 15:39:44 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/23 15:39:44 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			c_conv(va_list *ap, t_options *flag)
{
	int		width;

	if (flag->modifier == l)
		maj_c_conv(ap, flag);
	else
	{
		if ((width = flag->width - 1) < 0)
			width = 0;
		if (width && !flag->minus)
			flag->zero ? ft_putnchar('0', width) : ft_putnchar(' ', width);
		ft_putchar(va_arg(*ap, int));
		if (width && flag->minus)
			ft_putnchar(' ', width);
		flag->ret_printf += width + 1;
	}
}

void			maj_c_conv(va_list *ap, t_options *flag)
{
	wint_t		wchar;
	size_t		ret_utf8;

	(void)*flag;
	ret_utf8 = 0;
	wchar = va_arg(*ap, wint_t);
	count_octet(wchar, &ret_utf8);
	handle_wild_mask(wchar);
	flag->ret_printf += ret_utf8;
}
