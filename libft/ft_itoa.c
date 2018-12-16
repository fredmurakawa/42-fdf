/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbueno-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 14:00:05 by fbueno-m          #+#    #+#             */
/*   Updated: 2018/04/22 14:00:06 by fbueno-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	char			*str;
	size_t			len;
	unsigned int	cpy;

	len = ft_nbr_len(n);
	cpy = n;
	if (n < 0)
	{
		cpy = -n;
		len++;
	}
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (len)
	{
		str[--len] = cpy % 10 + '0';
		cpy /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
