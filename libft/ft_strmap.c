/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbueno-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 18:31:00 by fbueno-m          #+#    #+#             */
/*   Updated: 2018/04/21 18:31:02 by fbueno-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new_str;
	int		len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (!(new_str = ft_strnew(len)))
		return (NULL);
	while (len--)
		new_str[len] = f(s[len]);
	return (new_str);
}
