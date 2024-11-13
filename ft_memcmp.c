/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:37:32 by arpenel           #+#    #+#             */
/*   Updated: 2024/11/13 16:09:04 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    size_t i; 

    i = 0;
    while (i < n)
    {
        if ((unsigned char *)s1[i] != (unsigned char *)s2[i])
        {
            return ((unsigned char *)s1 - ((unsigned char *)s2)) 
        }
    i++;   
    }
    return (0);
}