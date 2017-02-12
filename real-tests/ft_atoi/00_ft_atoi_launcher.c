/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_tests_launcher.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 20:49:40 by vfour             #+#    #+#             */
/*   Updated: 2017/02/12 16:39:03 by vfour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_test.h"

int			ft_atoi_launcher(void)
{
	struct s_list_test	*l;

	puts("ft_atoi:");
	fill_test_list(&l, "basic_test", &basic_test);
	fill_test_list(&l, "neg_test", &neg_test);
	fill_test_list(&l, "emptystring_test", &emptystring_test);
	fill_test_list(&l, "intmin_test", &intmin_test);
	fill_test_list(&l, "intmax_test", &intmax_test);
	fill_test_list(&l, "overflow_test", &overflow_test);
	fill_test_list(&l, "zero_test", &zero_test);
	fill_test_list(&l, "plusplus_test", &plusplus_test);
	fill_test_list(&l, "plus_test", &plus_test);
	fill_test_list(&l, "plusneg_test", &plusneg_test);
	fill_test_list(&l, "negneg_test", &negneg_test);
	fill_test_list(&l, "negzero_test", &negzero_test);
	fill_test_list(&l, "pluszero_test", &pluszero_test);
	fill_test_list(&l, "letters_test", &letters_test);
	return (launch_tests(&l));
}
