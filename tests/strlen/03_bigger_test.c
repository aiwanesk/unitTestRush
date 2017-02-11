/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_bigger_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 16:00:30 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/02/11 16:00:31 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_test.h"

int		bigger_test(void)
{
	if (ft_strlen(LONGSTRING) == strlen(LONGSTRING))
		return (0);
	else
		return (1);
}
