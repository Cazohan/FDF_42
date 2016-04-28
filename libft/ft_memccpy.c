/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lherbelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 19:10:00 by lherbelo          #+#    #+#             */
/*   Updated: 2015/12/10 18:10:43 by lherbelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char		*strdest;
	const char	*strsrc;

	strdest = (char*)dest;
	strsrc = (char*)src;
	while (n > 0 && *strsrc != c)
	{
		n--;
		*strdest++ = *strsrc++;
	}
	if (n > 0)
	{
		*strdest++ = *strsrc++;
		return (strdest);
	}
	else
		return (NULL);
}
