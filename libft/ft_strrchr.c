/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lherbelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 16:49:04 by lherbelo          #+#    #+#             */
/*   Updated: 2015/12/10 14:48:09 by lherbelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s1, int c)
{
	int i;

	i = ft_strlen(s1);
	while (i >= 0)
	{
		if (s1[i] == (char)c)
			return ((char*)&s1[i]);
		i--;
	}
	return (NULL);
}
