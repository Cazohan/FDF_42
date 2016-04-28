/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lherbelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 13:01:40 by lherbelo          #+#    #+#             */
/*   Updated: 2015/12/10 18:11:25 by lherbelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*strdest;
	char	*strsrc;

	strsrc = (char*)src;
	strdest = (char*)dest;
	if (strsrc < strdest)
	{
		strsrc = strsrc + n - 1;
		strdest = strdest + n - 1;
		while (n > 0)
		{
			*strdest-- = *strsrc--;
			n--;
		}
	}
	else
	{
		while (n > 0)
		{
			*strdest++ = *strsrc++;
			n--;
		}
	}
	return (dest);
}
