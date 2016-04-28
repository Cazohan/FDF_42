/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lherbelo <lherbelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 15:59:12 by lherbelo          #+#    #+#             */
/*   Updated: 2016/04/27 18:30:31 by lherbelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

double			ft_color(int diff)
{
	if (diff <= 0)
		return (BLEU);
	else if (diff * 1.5 <= 1.0)
		return (VIOLET);
	else if (diff * 1.5 <= 2.0)
		return (MARRON);
	else if (diff *  1.5 <= 3.0)
		return (ROUGE_F);
	else if (diff * 1.5 <= 4.0)
		return (VERT);
	else if (diff * 1.5 <= 5.0)
		return (ROUGE);
	else if (diff * 1.5 <= 6.0)
		return (ORANGE);
	else if (diff * 1.5 <= 7.0)
		return (JAUNE);
	else if (diff * 1.5 <= 8.0)
		return (MAUVE);
	else if (diff * 1.5 <= 9.0)
		return (ROSE);
	else if (diff * 1.5 <= 10.0)
		return (CYAN);
	else;
		return (BLANC);
}

static int	ft_diff(int a, int b)
{
	double	i;

	i = 0;
	if (a < b)
	{
		while (a != b)
		{
			a++;
			i++;
		}
	}
	else
	{
		while (b != a)
		{
			b++;
			i++;
		}
	}
//	printf("diff = %lf\n", i);
	return (i);
}

int			ft_set_color(t_fdf *fdf, int pt1, int pt2)
{
	fdf->min = ft_intmin(pt1, pt2);
	fdf->max = ft_intmax(pt1, pt2);
	fdf->diff = ft_diff(fdf->min, fdf->max);
	return (fdf->diff);
}

