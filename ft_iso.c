/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iso.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lherbelo <lherbelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 16:23:03 by lherbelo          #+#    #+#             */
/*   Updated: 2016/04/18 13:52:38 by lherbelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"


void				put_img(t_fdf *fdf, int x, int y, int color)
{
	char			*data;
	unsigned int	value;

	data = fdf->addr;
	value = mlx_get_color_value(fdf->mlx, color);
	if (x > 0 && x < fdf->widght && y > 0 && y < fdf->height)
		ft_memcpy(data + y * fdf->s_l + x * (fdf->bpp / 8), &value, 3);
}

void				verti(t_fdf *fdf, t_coord *pt1, t_coord *pt2, int color)
{
	int 			i;

	i = pt1->y;
	while (i <= pt2->y)
	{
		put_img(fdf, pt1->x + ((pt2->x - pt1->x) * (i - pt1->y)) \
				/ (pt2->y - pt1->y), i,color);
		i++;
	}
}

void				hori(t_fdf *fdf, t_coord *pt1, t_coord *pt2, int color)
{
	int				i;

	i = pt1->x;
	while (i <= pt2->x)
	{
		put_img(fdf, i, pt1->y + ((pt2->y - pt1->y) * (i - pt1->x)) \
				/ (pt2->x - pt1->x), color);
		i++;
	}
}
