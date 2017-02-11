/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 15:49:28 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/02/11 19:24:48 by vfour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/framework.h"

t_enum_result	signal_handler(int signo)
{
	if (signo == SIGSEGV)
		return (SEGV);
	else if (signo == SIGBUS)
		return (BUSE);
	return (OTHER);
}

int				launch_tests(struct s_list_test **list)
{
	int						pid;
	int						error;
	struct s_list_test		*save_first;
	int						status;

	error = NONE;
	save_first = *list;
	while ((*list))
	{
		printf("name = %s\n", (*list)->name);
		if ((pid = fork()) == -1)
			exit(NONE);
		else if (pid > 0)
		{
			//recuperer le signal pour fill list
			//recuperer la valeur sinon
			puts("coucou\n");//timeoutLoop;
			wait(&status);
			if (WIFSIGNALED(status))
				(*list)->test_result = signal_handler(WTERMSIG(status));
			else if (WIFEXITED(status))
				(*list)->test_result = signal_handler(WEXITSTATUS(status));
		}
		else
		{
			error = (*list)->fun();
			ft_printf("error = %d\n", error);
			exit(error);
		}
		(*list) = (*list)->next;
		//remplir l'enum du parent la
	}
	(*list) = save_first;
	write_test_result((*list));
	return (error);
}
