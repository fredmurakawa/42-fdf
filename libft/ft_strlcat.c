/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbueno-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 10:59:01 by fbueno-m          #+#    #+#             */
/*   Updated: 2018/04/19 10:59:03 by fbueno-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	size_dst;
	size_t	size_src;
	size_t	i;
	size_t	j;

	size_dst = ft_strlen(dst);
	i = size_dst;
	size_src = ft_strlen(src);
	if (size_dst >= dstsize)
		return (dstsize + size_src);
	j = 0;
	while (src[j] != '\0' && (j + size_dst) < dstsize - 1)
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[j + size_dst] = '\0';
	return (size_dst + size_src);
}
