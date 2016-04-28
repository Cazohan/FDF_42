/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lherbelo <lherbelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 14:40:49 by lherbelo          #+#    #+#             */
/*   Updated: 2015/12/10 15:21:20 by lherbelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*strdest;
	const char	*strsrc;

	strdest = dest;
	strsrc = src;
	while (n > 0)
	{
		*strdest++ = *strsrc++;
		n--;
	}
	return (dest);
}
