#include "../lib_test.h"

int		ko_test(void)
{
	if (ft_strlen("qwe") == strlen(LONGSTRING))
		return (0);
	else
		return (1);
}
