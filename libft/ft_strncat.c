/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbueno-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 10:53:32 by fbueno-m          #+#    #+#             */
/*   Updated: 2018/04/19 10:53:34 by fbueno-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;
	size_t max;

	max = ft_strlen(s2) < n ? ft_strlen(s2) : n;
	i = 0;
	while (s1[i] != '\0')
		i++;
	if (s1[i] == '\0')
	{
		j = 0;
		while (j < max)
			s1[i++] = s2[j++];
		s1[i] = '\0';
	}
	return (s1);
}
