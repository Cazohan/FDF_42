/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lherbelo <lherbelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 17:41:54 by lherbelo          #+#    #+#             */
/*   Updated: 2015/12/08 00:46:15 by lherbelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char *cpy;

	cpy = dest;
	while (*dest != '\0')
		dest++;
	while (n-- != 0 && *src != '\0')
		*dest++ = *src++;
	*dest = '\0';
	return (cpy);
}
