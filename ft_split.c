/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:34:25 by arpenel           #+#    #+#             */
/*   Updated: 2024/11/25 15:46:27 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static int is_it_sep(char c, char sep)
{
	if (c == sep)
		return (1);
	return (0);
}

static int count_words(char *str, char sep)
{
	size_t	i;
	size_t	words;

	words = 0;
	i = 0;
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
	cpy = malloc(sizeof(char) * (ft_len_words(str, sep) + 1));
	if (!cpy)
		return (NULL);
	while (str[i] && i < len)
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	**ft_split(const char *s, char sep)
{
	char	**res;
	size_t	i;
	size_t	j;

	res = malloc(sizeof(char *) * (count_words((char *)s, sep) + 1));
	if (!s)
		return (0);
	
	i = 0;
	j = 0;
	while (s[i])
	{
		if (is_it_sep(s[i], sep) == 1)
			i++;
		else
		{
			res[j] = cpy_word(&s[i], sep, ft_len_words(&s[i], sep));
			j++;
			i = i + ft_len_words(&s[i], sep);
		}
	}
	res[j] = 0;
	return (res);
}

/*
int	main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	char **tab = ft_split(argv[1], ' ');
	int	i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
}
*/