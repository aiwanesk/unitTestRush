# include "../../printf/includes/ft_printf.h"
# include <sys/wait.h>
# include <signal.h>

typedef enum	t_enum_result{
	OK,
	KO,
	SEGV,
	BUSE,
	NONE
}				e_enum_result;

typedef struct	t_list_test{
	struct t_list_test	*next;
	char				*name;
	int					(*fun)();
	int					test_result;
}				s_list_test;

void					write_test_result(struct t_list_test *list_result);
void					fill_test_list(struct t_list_test **list, char *name, int (*fun)(void));
int						launch_tests(struct t_list_test **list);
