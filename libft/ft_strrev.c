/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lherbelo <lherbelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 01:22:17 by lherbelo          #+#    #+#             */
/*   Updated: 2015/12/12 01:30:19 by lherbelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char *str)
{
	char *ret;
	char tmp;

	ret = str + ft_strlen(str) - 1;
	while (str < ret)
	{
		tmp = *str;
		*str++ = *ret;
		*ret-- = tmp;
	}
}
