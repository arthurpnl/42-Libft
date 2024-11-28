/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:44:27 by arpenel           #+#    #+#             */
/*   Updated: 2024/11/28 08:38:03 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	i = 0;
	if (str = malloc(sizeof(const char) * ft_strlen(s) + 1))
	{
		str[ft_strlen(s)] = '\0';
	}
	else
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	return (str);
}
