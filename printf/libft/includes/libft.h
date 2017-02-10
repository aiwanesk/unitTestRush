/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/22 10:08:39 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/23 16:07:35 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <limits.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
**	----------> File manipulation functions <-----
*/
# define BUF_SIZE 512

typedef struct	s_gnl
{
	char			*buf;
	int				fd;
	int				ret;
	struct s_gnl	*next;
}				t_gnl;

int				ft_get_next_line(int const fd, char **line);

/*
**	----------> Number manipulation functions <-----
*/
char			*ft_itoa(int n);
char			*ft_ltoa(long n);
int				ft_intlen(int n);
int				ft_nlen(uintmax_t n, int base);
char			*ft_ntoa(uintmax_t n, const char *base);
int				ft_longlen(long n);

int				ft_pow(int x, int y);

void			ft_putdouble(double n, int prec);
char			*ft_dtoa(double n, int prec);

/*
**	----------> String manipulation functions <-----
*/
/*
**	Check
*/
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isblank(int c);
int				ft_iscntrl(int c);
int				ft_isdigit(int c);
int				ft_isgraph(int c);
int				ft_islower(int c);
int				ft_isprint(int c);
int				ft_ispunct(int c);
int				ft_isspace(int c);
int				ft_isupper(int c);
int				ft_isxdigit(int c);
int				ft_isnumber(int c);
int				ft_nlen(uintmax_t n, int base);
/*
**	Compare
*/
int				ft_strequ(char const *s1, char const *s2);
int				ft_strcaseequ(char const *s1, char const *s2);
int				ft_strncaseequ(char const *s1, char const *s2, size_t n);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strcasecmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strncasecmp(const char *s1, const char *s2, size_t n);

/*
**	Copy & Assign
*/
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t n);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);

/*
**	Create
*/
char			*ft_strnew(size_t size);
char			*ft_strdup(const char *s1);
char			*ft_strndup(const char *s1, size_t n);
char			*ft_random_string(int n);

/*
**	Free
*/
void			ft_strdel(char **as);
void			ft_strtabdel(char ***astrtab);
void			ft_strclr(char *s);

/*
**	Print
*/
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putnbr_separator(uintmax_t n, char *sep);
void			ft_putnbr_base(uintmax_t n, char *base);
void			ft_putlnbr(long n);
void			ft_putnbr_endl(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putnbr_endl_fd(int n, int fd);
void			ft_putnchar(char c, size_t n);
void			ft_putnstr(char const *s, size_t n);
void			ft_putnendl(char const *s, size_t n);
void			ft_error(const char *s, int n);
void			ft_putstrtab(char **tab);

/*
**	Search
*/
size_t			ft_strlen(const char *s);
size_t			ft_strnlen(const char *s, size_t maxlen);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstrchr(const char *s, const char *str);
char			*ft_strstr(const char *s1, const char *s2);
char			*ft_strrstr(const char *s1, const char *s2);
char			*ft_strcasestr(const char *s1, const char *s2);
char			*ft_strnstr(const char *s1, const char *s2, size_t n);
size_t			ft_wordcount(const char *s, char c);
size_t			ft_wordcountwith(const char *s, char *c);
size_t			ft_strtablen(char **tab);

/*
**	Transform
*/
int				ft_atoi(const char *s);
int				ft_tolower(int c);
int				ft_toupper(int c);
char			*ft_strrev(char *str);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoin_free(char *s1, char const *s2);
char			**ft_strsplit(char const *s, char c);
char			**ft_strsplitwith(char const *s, char *c);
char			**ft_strtabjoin(char **tab1, char **tab2);

/*
**	Misc
*/
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char	const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strtrim(char const *s);

/*
**	----------> Memory manipulation functions <-----
*/
/*
**	Compare
*/
int				ft_memcmp(const void *s1, const void *s2, size_t n);

/*
**	Copy & Assign
*/
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_realloc(void *ptr, size_t size);

/*
**	Create
*/
void			*ft_memalloc(size_t size);

/*
**	Free
*/
void			ft_memdel(void **ap);

/*
**	Search
*/
void			*ft_memchr(const void *s, int c, size_t n);

#endif
