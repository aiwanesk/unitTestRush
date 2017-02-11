#include "../lib_test.h"

int		bigger_test(void)
{
	if (ft_strlen(LONGSTRING) == strlen(LONGSTRING))
		return (0);
	else
		return (1);
}
