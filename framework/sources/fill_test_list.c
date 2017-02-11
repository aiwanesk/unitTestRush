#include "../includes/framework.h"

static void		add_end(struct t_list_test **list, char *name, int (*fun)())
{
	struct t_list_test	*add;
	struct t_list_test	*it;

	it = (*list);
	add = (struct t_list_test *)malloc(sizeof(struct t_list_test));
	add->name = ft_strdup(name);
	add->next = NULL;
	add->fun = fun;
	add->test_result = NONE;
	while (it->next != NULL)
		it = it->next;
	it->next = add;
}

static void		add_first(struct t_list_test **list, char *name, int (*fun)())
{
	struct t_list_test		*add;

	add = (struct t_list_test *)malloc(sizeof(struct t_list_test));
	add->name = ft_strdup(name);
	add->next = NULL;
	add->fun = fun;
	add->test_result = NONE;
	(*list) = add;
}

void			fill_test_list(struct t_list_test **list, char *name, int (*fun)())
{
	if ((*list) == NULL)
		add_first(list, name, fun);
	else
		add_end(list, name, fun);
}
