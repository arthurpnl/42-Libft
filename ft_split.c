/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:34:25 by arpenel           #+#    #+#             */
/*   Updated: 2024/11/21 22:38:48 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int is_it_sep(char c, char sep)
{
	int	i;

	i = 0;
	if (c == sep)
		return (1);
	return (0);
}

static int count_words(char *str, char sep)
{
	size_t	i;
	size_t	words;

	words = 0;
	while (str[i])
	{
		if (is_it_sep(str[i + 1], sep) == 1 && is_it_sep(str[i], sep) == 0)
			words++;
		i++;
	}
	return (words);
}

int	ft_len_words(const char *str, char sep)
{
	size_t	i;

	i = 0;
	while (str[i] && is_it_sep(str[i], sep) == 0)
		i++;
	return (i);
}

char	*cpy_word(const char	*str, char sep, size_t len)
{
	size_t	i;
	char	*cpy;

	i = 0;
	cpy = malloc(sizeoff(char) * (ft_len_words(str, sep) + 1));
	if (!cpy)
		return (NULL);
	while (str[i] && i < n)
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	**ft_split(const char *s, char c)
{
	char	*res;

	res = (char *)s;
	if (!s)
		return (NULL);
}