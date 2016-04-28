/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lherbelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 21:38:23 by lherbelo          #+#    #+#             */
/*   Updated: 2015/12/14 22:14:18 by lherbelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char *ret;

	ret = (unsigned char*)str;
	while (n > 0 && *ret != (unsigned char)c)
	{
		ret++;
		n--;
	}
	if (n == 0)
		return (NULL);
	else
		return (ret);
}
