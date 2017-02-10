/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/22 09:45:50 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/23 18:21:56 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define BASE_2		"01"
# define BASE_8		"01234567"
# define BASE_10	"0123456789"
# define BASE_16_L	"0123456789abcdef"
# define BASE_16_U	"0123456789ABCDEF"

# define CONV_TYPE	"sScCpDdioOuUxXbn%"
# define MOD_TYPE	"hjlz"

# include <stdarg.h>
# include <stdint.h>
# include <stddef.h>
# include <wchar.h>
# include <locale.h>
# include "../libft/includes/libft.h"

typedef	struct	s_options
{
	int			hash : 1;
	int			space : 1;
	int			minus : 1;
	int			plus : 1;
	int			zero : 1;
	int			sep : 1;
	int			got_prec : 1;
	int			got_width : 1;
	intmax_t	prec;
	intmax_t	width;
	size_t		ret_printf;
	enum
	{
		none,
		h,
		hh,
		l,
		ll,
		j,
		z
	}			modifier;
}				t_options;

typedef struct	s_utils_prec
{
	size_t		width;
	size_t		prec;
	size_t		len;
}				t_utils_prec;

int				ft_printf(const char *format, ...);

typedef void	(*t_func)(va_list *, t_options *);
t_func			*get_func_array(void);
void			handle_trial_prec(char c, t_options *flag);
void			handle_arg(va_list *ap, const char **format, t_options *flag);
void			get_prec_s(t_options *flag, t_utils_prec *s);
void			get_width_s(t_options *flag, t_utils_prec *s);
size_t			get_width(t_options *flag, size_t len, int prefix,
		uintmax_t nbr);
size_t			get_prec(t_options *flag, size_t len, uintmax_t nbr);
int				free_ft_printf(int set);
void			do_putnbr_separator(uintmax_t nbr);
int				count_sep(uintmax_t n);
void			count_octet(unsigned int wild_arg, size_t *ret);
void			handle_wild_mask(unsigned int wild_arg);
void			flag_handle(t_options *flag, uintmax_t nbr, char *base,
																char *prefix);
int				flag_opt(const char *format, t_options *flag, va_list *ap);
uintmax_t		apply_modifier(t_options *flag, va_list *ap);

void			id_conv(va_list *ap, t_options *flag);
void			maj_d_conv(va_list *ap, t_options *flag);
void			u_conv(va_list *ap, t_options *flag);
void			maj_u_conv(va_list *ap, t_options *flag);
void			o_conv(va_list *ap, t_options *flag);
void			maj_o_conv(va_list *ap, t_options *flag);
void			x_conv(va_list *ap, t_options *flag);
void			maj_x_conv(va_list *ap, t_options *flag);
void			p_conv(va_list *ap, t_options *flag);
void			c_conv(va_list *ap, t_options *flag);
void			maj_c_conv(va_list *ap, t_options *flag);
void			s_conv(va_list *ap, t_options *flag);
void			maj_s_conv(va_list *ap, t_options *flag);
void			n_conv(va_list *ap, t_options *flag);
void			b_conv(va_list *ap, t_options *flag);

void			f_conv(va_list *ap, t_options *flag);

#endif
