/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lherbelo <lherbelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 14:39:07 by lherbelo          #+#    #+#             */
/*   Updated: 2015/12/10 18:33:09 by lherbelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(const char *s)
{
	int		i;
	int		lon;
	char	*ret;

	if (s == NULL)
		return (NULL);
	lon = ft_strlen(s);
	while (s[lon - 1] == '\n' || s[lon - 1] == '\t' || s[lon - 1] == ' ')
		lon--;
	i = -1;
	while (s[++i] == '\t' || s[i] == '\n' || s[i] == ' ')
		lon--;
	if (lon <= 0)
		lon = 0;
	ret = ft_memalloc(lon + 1);
	if (ret == NULL)
		return (NULL);
	s += i;
	i = -1;
	while (++i < lon)
		ret[i] = *s++;
	ret[i] = '\0';
	return (ret);
}
