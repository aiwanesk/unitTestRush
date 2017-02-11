/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 15:49:28 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/02/11 20:55:01 by vfour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/framework.h"

static t_enum_result	signal_handler(int signo)
{
	if (signo == SIGSEGV)
		return (SEGV);
	else if (signo == SIGBUS)
		return (BUSE);
	return (OTHER);
}

static t_enum_result	return_handler(int ret)
{
	if (ret == 0)
		return (OK);
	else
		return (KO);
}

static void				test_handler(struct s_list_test **list)
{
	int			status;

	wait(&status);
	if (WIFSIGNALED(status))
		(*list)->test_result = signal_handler(WTERMSIG(status));
	else if (WIFEXITED(status))
		(*list)->test_result = return_handler(WEXITSTATUS(status));
	else
		(*list)->test_result = OTHER;
}

int						launch_tests(struct s_list_test **list)
{
	int						pid;
	int						error;
	struct s_list_test		*save_first;

	error = NONE;
	save_first = *list;
	while ((*list))
	{
		if ((pid = fork()) == -1)
			exit(NONE);
		else if (pid > 0)
			test_handler(list);
		else
		{
			error = (*list)->fun();
			exit(error);
		}
		(*list) = (*list)->next;
	}
	(*list) = save_first;
	write_test_result((*list));
	return (error);
}
