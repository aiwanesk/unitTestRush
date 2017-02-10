/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 20:15:26 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/02/11 20:15:28 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_end(t_list **alst, t_list *new)
{
	if (alst && new)
	{
		while ((*alst)->next != NULL)
			(*alst) = (*alst)->next;
		(*alst)->next = new;
	}
}
