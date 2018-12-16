/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbueno-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:54:23 by fbueno-m          #+#    #+#             */
/*   Updated: 2018/04/19 14:54:24 by fbueno-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		find_index;

	i = 0;
	find_index = -1;
	while (s[i])
	{
		if (s[i] == c)
			find_index = i;
		i++;
	}
	if (s[i] == c)
		find_index = i;
	if (find_index >= 0)
		return ((char *)(s + find_index));
	return (NULL);
}
