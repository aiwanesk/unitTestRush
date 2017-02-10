#include "../includes/framework.h"

static char			*convert_enum(int value)
{
	if (value == OK)
		return ("OK");
	else if (value == KO)
		return ("KO");
	else if (value == SEGV)
		return ("SEGV");
	else if (value == BUSE)
		return ("BUSE");
	else if (value == NONE)
		return ("NONE");
	else
		return ("ERROR");
}

static void			write_name_of_test_set(struct t_tree_test *list_result)
{
	ft_printf("Name of test set: %s\n", list_result->test_name);
}

static void			write_method_result(struct t_tree_test *list_result)
{
	char	*enum_to_string;

	enum_to_string = convert_enum(list_result->test_result);
	ft_printf("\t%s test : [%s]\n", list_result->test_name, enum_to_string);
}

void				write_test_result(struct t_tree_test *list_result){
	while (list_result)
	{
		if (list_result->bool_is_launcher == TRUE)
			write_name_of_test_set(list_result);
		else
			write_method_result(list_result);
		list_result = list_result->next;
	}
}
