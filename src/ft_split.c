/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarlee <bcarlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 15:48:45 by bcarlee           #+#    #+#             */
/*   Updated: 2021/12/08 14:23:53 by bcarlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	get_all_words(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*s)
	{
		if (*s == c)
			i = 0;
		else if (i == 0)
		{
			i = 1;
			j++;
		}
		s++;
	}
	return (j);
}

char	*add_word(char c, char const *s, unsigned int i)
{
	char	*p;
	int		j;
	int		f;

	j = i;
	f = 0;
	while (s[i] && f == 0)
	{
		if (s[i] == c)
		{
			p = ft_substr(s, j, (i - j));
			f = 1;
		}
		else if (s[i + 1] == '\0')
		{
			p = ft_substr(s, j, (i - j + 1));
			f = 1;
		}
		i++;
	}
	return (p);
}

void	mem_words(char **res, char c, char const *s)
{
	int				words;
	int				h;
	unsigned char	i;

	h = 0;
	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] == c)
			h = 0;
		else if (h == 0)
		{
			res[words] = add_word(c, s, i);
			words++;
			h = 1;
		}
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	int		all_words;
	char	**res;

	if (!s)
		return (NULL);
	all_words = get_all_words(s, c);
	res = malloc(sizeof(char *) * (all_words + 1));
	if (!res)
		return (NULL);
	mem_words(res, c, s);
	res[all_words] = NULL;
	return (res);
}
