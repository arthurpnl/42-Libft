/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:28:17 by arpenel           #+#    #+#             */
/*   Updated: 2024/12/09 13:30:14 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t    ft_countwords(const char *s, char c)
{
    size_t    i;
    size_t    words;

    words = 0;
    i = 0;
    while (s[i])
    {
        if ((!i || s[i - 1] == c) && s[i] != c)
            words++;
        i++;
    }
    return (words);
}

void    free_matrix(char **t)
{
    size_t    i;

    i = 0;
    while (t[i])
        free(t[i++]);
    free(t);
}

char    **ft_split(char const *s, char c)
{
    size_t    i;
    size_t    word;
    char    **ret;

    ret = ft_calloc((ft_countwords(s, c) + 1), sizeof(*ret));
    if (!ret)
        return (NULL);
    word = 0;
    i = 0;
    while (*s)
    {
        i = 1;
        if (*s != c)
        {
            while (s[i] && s[i] != c)
                i++;
            ret[word] = malloc(i + 1);
            if (!ret[word])
                return (free_matrix(ret), NULL);
            ft_strlcpy(ret[word++], s, i + 1);
        }
        s += i;
    }
    return (ret);
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
