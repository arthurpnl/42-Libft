/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:34:42 by arpenel           #+#    #+#             */
/*   Updated: 2024/11/22 16:51:57 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int ft_count(int n)
{
    size_t  i;

    i = 0;
    while (n != 0)
    {
        n /= 10;
        i++;
    }
    return (i);
}

char    *ft_itoa(int n)
{
    char    *res;
    size_t  count;
    long int    number;

    number = n;
    count = ft_count(n);
    if (number < 0)
    {
        number *= -1;
        count++;
    }

    res = malloc(sizeof(char *) * (count + 1));
    if (!res)
        return (NULL);

    res[count] = '\0';

    if (n == 0)
    {
        res[0] = '0';
        return (res);
    }

}