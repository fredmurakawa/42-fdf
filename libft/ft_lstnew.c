/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbueno-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 11:55:59 by fbueno-m          #+#    #+#             */
/*   Updated: 2018/04/23 11:56:00 by fbueno-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;
	void	*content_cpy;
	size_t	size_cpy;

	content_cpy = (void *)content;
	size_cpy = content_size;
	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		list->content = NULL;
		list->content_size = 0;
	}
	else
	{
		list->content = ft_memalloc(size_cpy);
		list->content = ft_memcpy(list->content, content_cpy, size_cpy);
		list->content_size = size_cpy;
	}
	list->next = NULL;
	return (list);
}
