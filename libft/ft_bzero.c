/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbueno-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:34:27 by fbueno-m          #+#    #+#             */
/*   Updated: 2018/04/19 15:34:28 by fbueno-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;

	if (n == 0)
		return ;
	i = -1;
	while (++i < n)
	{
		*(unsigned char*)(s + i) = (unsigned char)0;
	}
	return ;
}
