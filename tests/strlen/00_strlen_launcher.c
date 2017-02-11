/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_strlen_launcher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 16:00:12 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/02/11 16:00:19 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_test.h"

int			strlen_launcher(void)
{
	struct s_list_test	*l;

	puts("STRLEN:");
	fill_test_list(&l, "basic_test", &basic_test);
	fill_test_list(&l, "null_test", &null_test);
	fill_test_list(&l, "bigger_test", &bigger_test);
	fill_test_list(&l, "ko_test", &ko_test);
	//fill_test_list(&l, "bus_test", &bus_test);
	return (launch_tests(&l));
}
