/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/22 09:43:56 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/23 14:23:07 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *format, ...)
{
	t_options		flag;
	va_list			ap;
	int				i;

	i = 0;
	flag.ret_printf = 0;
	ft_bzero(&flag, sizeof(t_options));
	va_start(ap, format);
	while (format[i])
	{
		if (*format == '%')
			handle_arg(&ap, &format, &flag);
		else
		{
			ft_putchar(format[i]);
			flag.ret_printf++;
		}
		if (*format != '\0')
			format++;
	}
	va_end(ap);
	return (flag.ret_printf);
}
