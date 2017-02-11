#include "../lib_test.h"

int			strlen_launcher(void)
{
	struct t_list_test	*l;

	puts("STRLEN:");
	fill_test_list(&l, "basic_test", &basic_test);
	fill_test_list(&l, "null_test", &null_test);
	fill_test_list(&l, "bigger_test", &bigger_test);
	fill_test_list(&l, "ko_test", &ko_test);
	//fill_test_list(&l, "bus_test", &bus_test);
	return (launch_tests(&l));
}
