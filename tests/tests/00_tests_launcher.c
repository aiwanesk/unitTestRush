/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_tests_launcher.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 20:49:40 by vfour             #+#    #+#             */
/*   Updated: 2017/02/11 20:49:42 by vfour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_test.h"

int			tests_launcher(void)
{
	struct s_list_test	*l;

	puts("tests:");
	fill_test_list(&l, "ok_test", &ok_test);
	fill_test_list(&l, "ko_test", &ko_test);
	fill_test_list(&l, "segv_test", &segv_test);
	fill_test_list(&l, "bus_test", &bus_test);
	return (launch_tests(&l));
}
