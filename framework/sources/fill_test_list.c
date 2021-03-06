/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_test_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 15:49:19 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/02/11 15:53:37 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/framework.h"

static void		add_end(struct s_list_test **list, char *name, int (*fun)())
{
	struct s_list_test	*add;
	struct s_list_test	*it;

	it = (*list);
	add = (struct s_list_test *)malloc(sizeof(struct s_list_test));
	add->name = ft_strdup(name);
	add->next = NULL;
	add->fun = fun;
	add->test_result = NONE;
	while (it->next != NULL)
		it = it->next;
	it->next = add;
}

static void		add_first(struct s_list_test **list, char *name, int (*fun)())
{
	struct s_list_test		*add;

	add = (struct s_list_test *)malloc(sizeof(struct s_list_test));
	add->name = ft_strdup(name);
	add->next = NULL;
	add->fun = fun;
	add->test_result = NONE;
	(*list) = add;
}

void			fill_test_list(struct s_list_test **list, char *name,
		int (*fun)())
{
	if ((*list) == NULL)
		add_first(list, name, fun);
	else
		add_end(list, name, fun);
}
