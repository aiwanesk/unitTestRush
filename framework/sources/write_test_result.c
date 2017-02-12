/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_test_result.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 15:49:32 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/02/12 17:01:15 by vfour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static void			write_log(char *s, int val)
{
	int			fd;
	char		*tmp;
	char		*str;

	tmp = ft_strjoin(tmp, s);
	tmp = ft_strjoin(tmp, " test : ");
	tmp = ft_strjoin(tmp, convert_enum(val));
	fd = open("log_result", O_APPEND | O_CREAT | O_WRONLY, 0755);
	if (fd == 0)
	{
		ft_printf("Something went terrible wrong\n");
		exit(-1);
	}
	ft_putendl_fd(tmp, fd);
	close(fd);
	ft_printf("%s\n", tmp);
}

static int			write_method_result(struct s_list_test *list_result)
{
	char	*enum_to_string;

	enum_to_string = convert_enum(list_result->test_result);
	if (ft_strcmp(enum_to_string, "OK") == 0)
		ft_printf("\033[32m");
	else
		ft_printf("\033[31m");
	ft_printf("\t%s test : [%s]\n", list_result->name,
			convert_enum(list_result->test_result));
	ft_printf("\033[37m");
	write_log(list_result->name, list_result->test_result);
	if (ft_strcmp("OK", convert_enum(list_result->test_result)) == 0)
		return (0);
	return (1);
}

static void			write_number_error(int error)
{
	if (error != 0)
		ft_printf("%d error dans le test\n", error);
	else
		ft_printf("%d error dans le test\n", error);
}

void				write_test_result(struct s_list_test *list_result)
{
	int		error;

	error = 0;
	while (list_result)
	{
		error += write_method_result(list_result);
		list_result = list_result->next;
	}
	write_number_error(error);
}
