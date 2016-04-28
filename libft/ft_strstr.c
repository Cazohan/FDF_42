/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lherbelo <lherbelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 19:48:29 by lherbelo          #+#    #+#             */
/*   Updated: 2015/12/04 16:22:54 by lherbelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	const char *first;
	const char *second;

	if (*s2 == '\0')
		return ((char*)s1);
	while (*s1 != '\0')
	{
		first = s1;
		second = s2;
		while (*second != '\0' && *first == *second)
		{
			first++;
			second++;
		}
		if (*second == '\0')
			return ((char*)s1);
		s1++;
	}
	return (NULL);
}
