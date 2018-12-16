/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbueno-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 13:31:08 by fbueno-m          #+#    #+#             */
/*   Updated: 2018/04/19 13:31:09 by fbueno-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *needl, size_t len)
{
	size_t i;
	size_t n;
	size_t first;

	i = 0;
	if (needl[0] == '\0')
		return ((char *)hay);
	while (hay[i] != '\0' && i < len)
	{
		n = 0;
		if (hay[i] == needl[n])
		{
			first = i;
			while (hay[i] == needl[n] && i < len)
			{
				if (needl[n + 1] == '\0')
					return ((char *)&hay[first]);
				n++;
				i++;
			}
			i = first;
		}
		i++;
	}
	return (NULL);
}
