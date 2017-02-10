/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 15:40:07 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/23 15:40:08 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			p_conv(va_list *ap, t_options *flag)
{
	unsigned long	ptr;

	flag->sep = 0;
	flag->modifier = z;
	ptr = apply_modifier(flag, ap);
	if (!ptr && flag->got_prec && !flag->prec)
	{
		if (!flag->width)
			flag->ret_printf++;
		if (flag->width > 1 && !flag->minus)
		{
			ft_putnchar(' ', flag->width - 2);
			flag->ret_printf += flag->width - 1;
		}
		ft_putstr("0x");
		flag->ret_printf++;
		if (flag->width > 1 && flag->minus)
		{
			ft_putnchar(' ', flag->width - 2);
			flag->ret_printf += flag->width - 1;
		}
		return ;
	}
	flag_handle(flag, ptr, BASE_16_L, "0x");
}
