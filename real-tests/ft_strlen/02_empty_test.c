/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_empty_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 17:20:33 by vfour             #+#    #+#             */
/*   Updated: 2017/02/12 17:20:47 by vfour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_test.h"

int		empty_test(void)
{
	if (ft_strlen("") == strlen(""))
		return (0);
	else
		return (1);
}
