/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 20:24:11 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/06/01 10:30:41 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countword(const char *s, char c)
{
	size_t		i;
	size_t		occ;

	i = 0;
	occ = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			occ++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (occ);
}

static char		*ft_addword(const char *s, char c, size_t i)
{
	size_t		len;
	char		*str;

	len = i;
	while (s[len] && s[len] != c)
		len++;
	if (!(str = ft_strnew(len - i)))
		return (NULL);
	str = ft_strsub(s, i, len - i);
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t		i;
	size_t		j;
	char		**tab;

	j = 0;
	i = 0;
	tab = NULL;
	if (!s)
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(char *) * ft_countword(s, c) + 1)))
		return (NULL);
	while (j < ft_countword(s, c))
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			tab[j++] = ft_addword(s, c, i);
		while (s[i] != c && s[i])
			i++;
	}
	tab[j] = NULL;
	return (tab);
}
