/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 15:40:20 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/23 15:40:24 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			u_conv(va_list *ap, t_options *flag)
{
	flag_handle(flag, apply_modifier(flag, ap), BASE_10, NULL);
}

void			maj_u_conv(va_list *ap, t_options *flag)
{
	flag->modifier = l;
	u_conv(ap, flag);
}
