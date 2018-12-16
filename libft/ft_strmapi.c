/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbueno-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 19:08:27 by fbueno-m          #+#    #+#             */
/*   Updated: 2018/04/21 19:08:28 by fbueno-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_str;
	unsigned int	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (!(new_str = ft_strnew(len)))
		return (NULL);
	while (len--)
		new_str[len] = f(len, s[len]);
	return (new_str);
}
