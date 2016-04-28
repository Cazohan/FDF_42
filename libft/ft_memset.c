/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lherbelo <lherbelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 01:29:17 by lherbelo          #+#    #+#             */
/*   Updated: 2015/11/27 12:09:14 by lherbelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char *swt;

	swt = (unsigned char*)str;
	while (n > 0)
	{
		*swt = (unsigned char)c;
		swt++;
		n--;
	}
	return (str);
}
