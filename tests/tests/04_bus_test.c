/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_bus_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 20:43:34 by vfour             #+#    #+#             */
/*   Updated: 2017/02/11 20:43:36 by vfour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_test.h"

int		bus_test(void)
{
	if (ft_strcpy("truc", "Hello") == strcpy("truc", "Hello"))
		return (0);
	else
		return (1);
}