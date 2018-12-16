/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbueno-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 21:47:36 by fbueno-m          #+#    #+#             */
/*   Updated: 2018/04/21 21:47:38 by fbueno-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	is_delim(char s, char del)
{
	if (s == del)
		return (1);
	return (0);
}

static char	**count_letters(char const *s, char c, char **array)
{
	int		letters;
	int		i;
	int		j;
	int		array_ite;

	i = 0;
	array_ite = 0;
	while (s[i] != '\0')
	{
		letters = 0;
		while (is_delim(s[i], c) && s[i] != '\0')
			i++;
		while (!is_delim(s[i], c) && s[i] != '\0')
		{
			i++;
			letters++;
		}
		j = i - 1;
		if (letters > 0)
			array[array_ite] = ft_strnew(letters);
		while (letters--)
			array[array_ite][letters] = s[j--];
		array_ite++;
	}
	return (array);
}

char		**ft_strsplit(char const *s, char c)
{
	int		words;
	char	**array;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	if (!(array = (char **)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	array[words] = (void*)0;
	array = count_letters(s, c, array);
	return (array);
}
