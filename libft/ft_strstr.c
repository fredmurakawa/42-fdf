/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbueno-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 11:38:10 by fbueno-m          #+#    #+#             */
/*   Updated: 2018/04/19 11:38:11 by fbueno-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int n;
	int first;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		n = 0;
		if (haystack[i] == needle[n])
		{
			first = i;
			while (haystack[i] == needle[n])
			{
				if (needle[n + 1] == '\0')
					return ((char *)&haystack[first]);
				n++;
				i++;
			}
			i = first;
		}
		i++;
	}
	return (NULL);
}
