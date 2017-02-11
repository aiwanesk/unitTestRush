/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 15:49:28 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/02/11 15:49:29 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/framework.h"

int			launch_tests(struct t_list_test **list)
{
	int						pid;
	int						error;
	struct t_list_test		*save_first;

	error = NONE;
	save_first = *list;
	while ((*list))
	{
		printf("name = %s\n", (*list)->name);
		if ((pid = fork()) == -1)
			exit(NONE);
		else if (pid > 0)
			puts("coucou\n");//timeoutLoop;
		else
		{
			//recuperer le signal pour fill list
			//recuperer la valeur sinon
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
