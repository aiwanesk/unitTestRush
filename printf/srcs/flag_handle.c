/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/22 09:43:52 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/23 14:09:42 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_nbr(t_options *flag, uintmax_t nbr, char *base)
{
	if (!nbr && flag->got_prec && !flag->prec)
		return ;
	else
		flag->sep ? do_putnbr_separator(nbr) : ft_putnbr_base(nbr, base);
}

static void		exception(t_utils_prec *d, t_options *flag, char *prefix)
{
	if ((int)(d->len + d->prec) == flag->prec && prefix
				&& (!ft_strcmp(prefix, "0x") || !ft_strcmp(prefix, "0X")))
	{
		if (d->width > d->prec)
			d->width -= d->prec;
	}
}

void			flag_handle(t_options *flag, uintmax_t nbr, char *base,
																char *prefix)
{
	t_utils_prec	d;
	size_t			len_prefix;

	len_prefix = prefix ? ft_strlen(prefix) : 0;
	if (flag->got_prec)
		flag->zero = 0;
	d.len = flag->sep ? count_sep(nbr) : 0;
	d.len += ft_nlen(nbr, ft_strlen(base));
	d.width = get_width(flag, d.len, len_prefix, nbr);
	d.prec = get_prec(flag, d.len, nbr);
	exception(&d, flag, prefix);
	flag->ret_printf += d.width + d.prec + d.len + len_prefix;
	if (!nbr && flag->got_prec && !flag->prec)
		d.width ? d.width++ : flag->ret_printf--;
	if (prefix && flag->zero)
		ft_putstr(prefix);
	if (!flag->minus)
		flag->zero ? ft_putnchar('0', d.width) : ft_putnchar(' ', d.width);
	if (prefix && !flag->zero)
		ft_putstr(prefix);
	if (d.prec)
		ft_putnchar('0', d.prec);
	print_nbr(flag, nbr, base);
	if (flag->minus)
		ft_putnchar(' ', d.width);
}
