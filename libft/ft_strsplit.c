/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lherbelo <lherbelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 18:05:15 by lherbelo          #+#    #+#             */
/*   Updated: 2015/12/20 16:16:01 by lherbelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*ft_str_chr(const char *s, char c, int skip)
{
	if (skip)
		while (*s != '\0' && *s == c)
			s++;
	else
		while (*s != '\0' && *s != c)
			s++;
	return (s);
}

static int			ft_count_cut(const char *s, char c)
{
	int				icount;

	icount = 0;
	while (*s != '\0')
	{
		s = ft_str_chr(s, c, 1);
		if (*s != '\0')
		{
			icount++;
			s = ft_str_chr(s, c, 0);
		}
	}
	return (icount);
}

static char			**ft_tabclr(char **tabfree, int len)
{
	int				iclr;

	iclr = 0;
	while (iclr < len)
		free(tabfree[iclr]);
	free(tabfree);
	return (NULL);
}

char				**ft_strsplit(char const *s, char c)
{
	char			**newtab;
	int				i;
	const char		*suiv;

	if (s == NULL)
		return (NULL);
	newtab = (char**)malloc(sizeof(char*) * (ft_count_cut(s, c) + 1));
	if (newtab == NULL)
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		s = ft_str_chr(s, c, 1);
		if (*s != '\0')
		{
			suiv = ft_str_chr(s, c, 0);
			newtab[i] = ft_strsub(s, 0, suiv - s);
			if (newtab[i] == NULL)
				return (ft_tabclr(newtab, i));
			i++;
			s = suiv;
		}
	}
	newtab[i] = 0;
	return (newtab);
}
