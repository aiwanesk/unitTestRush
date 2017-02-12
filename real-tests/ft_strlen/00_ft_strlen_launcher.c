/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_ft_srtlen_launcher.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 17:19:52 by vfour             #+#    #+#             */
/*   Updated: 2017/02/12 17:21:01 by vfour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_test.h"

int			ft_strlen_launcher(void)
{
	struct s_list_test	*l;

	puts("ft_strlen:");
	fill_test_list(&l, "strlenbasic_test", &strlenbasic_test);
	fill_test_list(&l, "empty_test", &empty_test);
	return (launch_tests(&l));
}
