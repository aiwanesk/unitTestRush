/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_test.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 16:01:44 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/02/12 17:21:54 by vfour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_TEST_H
# define LIB_TEST_H
# include "../framework/includes/framework.h"
# include <string.h>

# define LONGSTRING "invraisemblables semblent vrais, car dans cette vie"

int		ft_atoi_launcher(void);
int		basic_test(void);
int		neg_test(void);
int		emptystring_test(void);
int		intmin_test(void);
int		intmax_test(void);
int		overflow_test(void);
int		zero_test(void);
int		plusplus_test(void);
int		plus_test(void);
int		plusneg_test(void);
int		negneg_test(void);
int		negzero_test(void);
int		pluszero_test(void);
int		letters_test(void);

int		ft_strlen_launcher(void);
int		strlenbasic_test(void);
int		empty_test(void);

#endif
