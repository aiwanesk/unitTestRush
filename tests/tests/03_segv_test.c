/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_segv_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 20:43:49 by vfour             #+#    #+#             */
/*   Updated: 2017/02/11 20:43:50 by vfour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_test.h"

int		segv_test(void)
{
	if (ft_strlen(NULL) == strlen(NULL))
		return (0);
	else
		return (1);
}