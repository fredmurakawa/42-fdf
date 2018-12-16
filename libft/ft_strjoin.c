/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbueno-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 20:00:27 by fbueno-m          #+#    #+#             */
/*   Updated: 2018/04/21 20:00:30 by fbueno-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	lens1;
	size_t	lens2;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	if (!(ret = (char *)malloc(sizeof(char) * (lens1 + lens2) + 1)))
		return (NULL);
	ret[lens1 + lens2] = '\0';
	i = 0;
	while (lens1--)
	{
		ret[i] = s1[i];
		i++;
	}
	j = 0;
	while (lens2--)
		ret[i++] = s2[j++];
	return (ret);
}
