/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lherbelo <lherbelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 15:59:12 by lherbelo          #+#    #+#             */
/*   Updated: 2016/05/04 16:51:41 by lherbelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

//void		ft_print_tout(t_fdf *fdf, int z)

/*	printf("\nmini= %d maxi= %d\n", fdf->min, fdf->max);
	printf("diff 1.5 = %f\n", fdf->diff / 1.5);
	printf("diff 2 = %f\n", fdf->diff / 2);
	printf("diff 3 = %f\n", fdf->diff / 3);
	printf("diff 4 = %f\n", fdf->diff / 4);
	printf("diff 5 = %f\n", fdf->diff / 5);
	printf("diff 6 = %f\n", fdf->diff / 6);
	printf("diff 7 = %f\n", fdf->diff / 7);
	printf("diff 8 = %f\n", fdf->diff / 8);
	printf("diff 9 = %f\n", fdf->diff / 9);
	printf("diff total = %f\n", fdf->diff);*/
//	printf("diff= %f, z= %d, ==%f==\n", fdf->diff, z, (fdf->diff / z));


int			ft_color(t_fdf *fdf, int z)
{
	if (z == fdf->min)
		return (BLEU);
	else if ((fdf->diff / z) <= (fdf->diff / 1.2))
		return (VIOLET);
	else if ((fdf->diff / z) <= (fdf->diff / 2))
		return (MARRON);
	else if ((fdf->diff / z) <= (fdf->diff / 3))
		return (ROUGE_F);
	else if ((fdf->diff / z) <= (fdf->diff / 4))
		return (VERT);
	else if ((fdf->diff / z) <= (fdf->diff / 5))
		return (ROUGE);
	else if ((fdf->diff / z) <= (fdf->diff / 6))
		return (ORANGE);
	else if ((fdf->diff / z) <= (fdf->diff / 7))
		return (JAUNE);
	else if ((fdf->diff / z) <= (fdf->diff / 8))
		return (MAUVE);
	else if ((fdf->diff / z) <= (fdf->diff / 9))
		return (CYAN);
	else
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

int			ft_set_color(t_fdf *fdf, int pt1)
{
	fdf->min = ft_intmin(fdf->min, pt1);
	fdf->max = ft_intmax(fdf->max, pt1);
	fdf->diff = ft_diff(fdf->min, fdf->max);
	return (fdf->diff);
}



