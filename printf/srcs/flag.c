/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/22 09:43:43 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/23 14:22:46 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		modifier_opt(const char *format, t_options *flag, int *i)
{
	if (flag->modifier == none && ft_strchr(MOD_TYPE, format[*i]))
	{
		if (format[*i] == 'h' && format[*i + 1] == 'h')
		{
			flag->modifier = hh;
			(*i)++;
		}
		else if (format[*i] == 'h')
			flag->modifier = h;
		else if (format[*i] == 'l' && format[*i + 1] == 'l')
		{
			flag->modifier = ll;
			(*i)++;
		}
		else if (format[*i] == 'l')
			flag->modifier = l;
		else if (format[*i] == 'j')
			flag->modifier = j;
		else
			flag->modifier = z;
		return (1);
	}
	return (0);
}

static int		width_opt(const char *form, t_options *flag,
		int *i, va_list *ap)
{
	if (form[*i] == '*')
	{
		flag->got_width = 1;
		flag->width = va_arg(*ap, int);
		if (flag->width < 0)
		{
			flag->minus = 1;
			flag->zero = 0;
			flag->width = -flag->width;
		}
	}
	else if (ft_isdigit(form[*i]))
	{
		flag->got_width = 1;
		flag->width = ft_atoi(&form[*i]);
		*i = *i + ft_intlen(flag->width) - 1;
	}
	else
		return (0);
	return (1);
}

static int		prec_opt(const char *form, t_options *flag, int *i, va_list *ap)
{
	if (form[*i] == '.' && ft_isdigit(form[*i + 1]))
	{
		flag->got_prec = 1;
		if ((flag->prec = ft_atoi(&form[++*i])) < 0)
			flag->prec = 0;
		*i += ft_intlen(flag->prec) - 1;
	}
	else if (form[*i] == '.' && form[*i + 1] == '*')
	{
		flag->prec = va_arg(*ap, int);
		flag->got_prec = flag->prec < 0 ? 0 : 1;
		(*i)++;
	}
	else if (form[*i] == '.')
	{
		flag->got_prec = 1;
		flag->prec = 0;
	}
	else
		return (0);
	return (1);
}

static int		handle_flag(const char *format, t_options *flag, int i)
{
	if (format[i] == '#')
		flag->hash = 1;
	else if (format[i] == '\'')
		flag->sep = 1;
	else if (format[i] == ' ')
		flag->space = flag->plus ? 0 : 1;
	else if (format[i] == '-')
	{
		flag->minus = 1;
		flag->zero = 0;
	}
	else if (format[i] == '0')
		flag->zero = flag->minus ? 0 : 1;
	else if (format[i] == '+')
	{
		flag->plus = 1;
		flag->space = 0;
	}
	else
		return (0);
	return (1);
}

int				flag_opt(const char *format, t_options *flag, va_list *ap)
{
	int		i;

	i = 1;
	while (!ft_strchr(CONV_TYPE, format[i]))
	{
		if (handle_flag(format, flag, i) == 1)
			i++;
		else if (width_opt(format, flag, &i, ap) == 1
				|| prec_opt(format, flag, &i, ap) == 1
				|| modifier_opt(format, flag, &i) == 1)
			i++;
		else
			break ;
	}
	return (i);
}
