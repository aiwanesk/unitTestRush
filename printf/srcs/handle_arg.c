/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/22 09:44:00 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/23 18:44:56 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define LANORME (t_func)*(f + (int)**format)

static void		reset_flag_info(t_options *flag)
{
	int		tmp;

	tmp = flag->ret_printf;
	ft_bzero(flag, sizeof(t_options));
	flag->ret_printf = tmp;
}

static void		set_list_opt(t_func *type_choice)
{
	type_choice['s'] = &s_conv;
	type_choice['S'] = &maj_s_conv;
	type_choice['c'] = &c_conv;
	type_choice['C'] = &maj_c_conv;
	type_choice['p'] = &p_conv;
	type_choice['D'] = &maj_d_conv;
	type_choice['d'] = &id_conv;
	type_choice['i'] = &id_conv;
	type_choice['o'] = &o_conv;
	type_choice['O'] = &maj_o_conv;
	type_choice['u'] = &u_conv;
	type_choice['U'] = &maj_u_conv;
	type_choice['x'] = &x_conv;
	type_choice['X'] = &maj_x_conv;
	type_choice['b'] = &b_conv;
	type_choice['n'] = &n_conv;
}

t_func			*get_func_array(void)
{
	static t_func	*type_choice = NULL;

	if (free_ft_printf(0))
	{
		if (type_choice != NULL)
		{
			free(type_choice);
			type_choice = NULL;
		}
		return (NULL);
	}
	if (type_choice == NULL)
	{
		type_choice = ft_memalloc(sizeof(t_func) * 256);
		if (type_choice)
			set_list_opt(type_choice);
	}
	return (type_choice);
}

void			handle_trial_prec(char c, t_options *flag)
{
	if (flag->width > 1 && !flag->minus)
	{
		if (flag->zero)
			ft_putnchar('0', flag->width - 1);
		else
			ft_putnchar(' ', flag->width - 1);
		flag->ret_printf = flag->ret_printf + flag->width - 1;
	}
	ft_putchar(c);
	flag->ret_printf++;
	if (flag->width > 1 && flag->minus)
	{
		ft_putnchar(' ', flag->width - 1);
		flag->ret_printf = flag->ret_printf + flag->width - 1;
	}
}

void			handle_arg(va_list *ap, const char **format, t_options *flag)
{
	int			flag_len;
	t_func		*f;

	f = get_func_array();
	flag_len = flag_opt(*format, flag, ap);
	*format = *format + flag_len;
	if (*(f + (int)**format) == NULL)
	{
		if (**format != '\0')
			handle_trial_prec(**format, flag);
	}
	else
		(LANORME)(ap, flag);
	reset_flag_info(flag);
}
