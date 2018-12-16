/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbueno-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 20:14:10 by fbueno-m          #+#    #+#             */
/*   Updated: 2018/04/21 20:14:11 by fbueno-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	char	*ret;
	int		len;
	int		i;

	if (!s)
		return (NULL);
	while (*s && (*s == ' ' || *s == '\n' || *s == '\t'))
		s++;
	len = ft_strlen(s) == 0 ? 0 : ft_strlen(s) - 1;
	if (len > 0)
	{
		while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
			len--;
		len++;
	}
	if (!(ret = (char *)malloc(sizeof(*ret) * len + 1)))
		return (NULL);
	ret[len] = '\0';
	i = 0;
	while (len--)
		ret[i++] = *s++;
	return (ret);
}
