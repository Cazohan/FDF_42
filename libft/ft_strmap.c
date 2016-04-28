/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lherbelo <lherbelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 15:21:27 by lherbelo          #+#    #+#             */
/*   Updated: 2015/12/10 18:21:11 by lherbelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*ret;
	int		i;

	if (s == NULL || f == NULL)
		return (NULL);
	ret = ft_memalloc(ft_strlen(s) + 1);
	if (ret == NULL)
		return (NULL);
	i = -1;
	while (s[++i])
	{
		ret[i] = f(s[i]);
	}
	ret[i] = '\0';
	return (ret);
}
