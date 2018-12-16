/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbueno-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:15:17 by fbueno-m          #+#    #+#             */
/*   Updated: 2018/04/23 15:15:18 by fbueno-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst;

	if (!lst || !f)
		return (NULL);
	new_lst = f(lst);
	if (new_lst != NULL || lst->next != NULL)
		new_lst->next = ft_lstmap(lst->next, f);
	return (new_lst);
}
