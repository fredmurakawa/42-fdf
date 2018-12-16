/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbueno-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 12:12:41 by fbueno-m          #+#    #+#             */
/*   Updated: 2018/04/22 12:12:44 by fbueno-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_delimiter(char s, char del)
{
	if (s == del)
		return (1);
	return (0);
}

int			ft_count_words(char const *s, char c)
{
	int		words;
	int		i;

	words = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (is_delimiter(s[i], c) && s[i] != '\0')
			i++;
		words = words + (s[i] != '\0' ? 1 : 0);
		while (!is_delimiter(s[i], c) && s[i] != '\0')
			i++;
	}
	return (words);
}
