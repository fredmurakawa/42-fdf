/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbueno-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 20:40:32 by fbueno-m          #+#    #+#             */
/*   Updated: 2018/04/19 20:40:34 by fbueno-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*ret;

	ret = dst;
	if ((unsigned char*)src == (unsigned char*)dst)
		return (ret);
	if ((unsigned char*)src < (unsigned char*)dst)
	{
		src = src + len - 1;
		dst = dst + len - 1;
		while (len--)
			*(unsigned char*)dst-- = *(unsigned char*)src--;
	}
	else
	{
		while (len--)
			*(unsigned char*)dst++ = *(unsigned char*)src++;
	}
	return (ret);
}
