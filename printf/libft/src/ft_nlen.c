/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nlen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/22 10:37:52 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/22 10:38:41 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int			ft_nlen(uintmax_t n, int base)
{
	int		len;

	if (!n)
		return (1);
	len = 0;
	if (base > 1)
	{
		while (n)
		{
			n /= base;
			len++;
		}
	}
	return (len);
}
