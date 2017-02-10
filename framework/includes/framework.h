# include "../../printf/includes/ft_printf.h"
# include <sys/wait.h>
# include <signal.h>

typedef enum	t_bool_launcher{
	TRUE,
	FALSE
}				s_bool_launcher;

typedef enum	t_enum_result{
	OK,
	KO,
	SEGV,
	BUSE,
	NONE
}				e_enum_result;

typedef struct	t_tree_test{
	int						bool_is_launcher;
	int						test_result;
	char					*test_name;
	struct t_tree_test		*next;
}				s_tree_test;

void					write_test_result(struct t_tree_test *list_result);
