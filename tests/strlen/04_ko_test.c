/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_ko_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 16:00:33 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/02/11 16:00:34 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_test.h"

int		ko_test(void)
{
	if (ft_strlen("qwe") == strlen(LONGSTRING))
		return (0);
	else
		return (1);
}
