/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 15:40:11 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/23 15:40:14 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			s_conv(va_list *ap, t_options *flag)
{
	char			*str;
	int				to_free;
	t_utils_prec	s;

	to_free = 0;
	if (flag->modifier == l)
		maj_s_conv(ap, flag);
	else
	{
		if (!(str = va_arg(*ap, char *)))
		{
			str = ft_strdup("(null)");
			to_free = 1;
		}
		s.len = ft_strlen(str);
		get_prec_s(flag, &s);
		get_width_s(flag, &s);
		flag->ret_printf += s.width + s.prec;
		if (s.width && !flag->minus)
			flag->zero ? ft_putnchar('0', s.width) : ft_putnchar(' ', s.width);
		flag->got_prec ? ft_putnstr(str, s.prec) : ft_putstr(str);
		if (s.width && flag->minus)
			ft_putnchar(' ', s.width);
		to_free ? ft_strdel(&str) : 0;
	}
}
