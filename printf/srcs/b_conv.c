/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 15:39:40 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/23 15:39:41 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			b_conv(va_list *ap, t_options *flag)
{
	flag->hash = 0;
	flag->sep = 0;
	flag_handle(flag, apply_modifier(flag, ap), BASE_2, "0b");
}
