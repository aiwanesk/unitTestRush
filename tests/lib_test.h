/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_test.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 16:01:44 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/02/12 17:02:04 by vfour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_TEST_H
# define LIB_TEST_H
# include "../framework/includes/framework.h"
# include <string.h>

# define LONGSTRING "invraisemblables semblent vrais, car dans cette vie"

int		tests_launcher(void);
int		ok_test(void);
int		ko_test(void);
int		segv_test(void);
int		bus_test(void);

#endif
