/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   framework.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 15:50:48 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/02/12 16:38:13 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAMEWORK_H
# define FRAMEWORK_H

# include "../../printf/includes/ft_printf.h"
# include <sys/wait.h>
# include <signal.h>
# include <fcntl.h>

typedef enum			e_enum_result{
	OK,
	KO,
	SEGV,
	BUSE,
	OTHER,
	NONE
}						t_enum_result;

typedef struct			s_list_test{
	struct s_list_test	*next;
	char				*name;
	int					(*fun)();
	int					test_result;
}						t_list_test;

void					write_test_result(struct s_list_test *list_result);
void					fill_test_list(struct s_list_test **list,
		char *name, int (*fun)(void));
int						launch_tests(struct s_list_test **list);

#endif
