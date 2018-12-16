/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbueno-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:53:39 by fbueno-m          #+#    #+#             */
/*   Updated: 2018/04/23 14:53:40 by fbueno-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*current_node;
	t_list	*tmp;

	current_node = *alst;
	if (!current_node || !del)
		return ;
	while (current_node)
	{
		tmp = current_node;
		ft_lstdelone(&current_node, del);
		current_node = tmp->next;
	}
	*alst = NULL;
}
