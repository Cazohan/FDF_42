/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lherbelo <lherbelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 01:01:29 by lherbelo          #+#    #+#             */
/*   Updated: 2015/12/13 04:42:17 by lherbelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dest, const char *src, size_t destsize)
{
	char		*dst;
	const char	*srce;
	size_t		i;
	size_t		len;

	i = destsize;
	dst = dest;
	srce = src;
	while (i-- != 0 && *dst != '\0')
		dst++;
	len = dst - dest;
	i = destsize - len;
	if (i == 0)
		return (len + ft_strlen(srce));
	while (*srce != '\0')
	{
		if (i != 1)
		{
			*dst++ = *srce;
			i--;
		}
		srce++;
	}
	*dst = '\0';
	return (len + (srce - src));
}
