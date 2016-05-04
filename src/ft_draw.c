/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lherbelo <lherbelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 12:26:24 by lherbelo          #+#    #+#             */
/*   Updated: 2016/05/04 15:39:02 by lherbelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void			line(t_fdf *fdf, t_coord *pt1, t_coord *pt2, int color)
{
	if ((abs(pt1->x - pt2->x))> (abs(pt1->y - pt2->y)))
	{
		if (pt1->x < pt2->x)
			hori(fdf, pt1, pt2, color);
		else
			hori(fdf, pt2, pt1, color);
	}
	else
	{
		if (pt1->y < pt2->y)
			verti(fdf, pt1, pt2, color);
		else
			verti(fdf, pt2, pt1, color);
	}
}


t_coord			made_pts(int x, int y, int z)
{
	t_coord		pts;
	
	pts.x = x;
	pts.y = y;
	pts.z = z;
	return (pts);
}

void			to_iso(t_fdf *fdf, t_coord *pts)
{
	t_coord		tmp;

	tmp.x = pts->x;
	tmp.y = pts->y;
	tmp.z = pts->z;
	pts->x = tmp.x * 2 - tmp.y * 2;
	pts->y = tmp.x + tmp.y - tmp.z * fdf->relief;
	pts->x *= fdf->zoom;
	pts->y *= fdf->zoom;
	pts->x += fdf->xpos;
	pts->y += fdf->ypos;
}

void			square(t_fdf *fdf, t_coord pt1, t_coord pt2, t_coord pt3)
{
	to_iso(fdf, &pt1);
	to_iso(fdf, &pt2);
	to_iso(fdf, &pt3);
	line(fdf, &pt1, &pt2, ft_color(fdf, ft_intmax(pt1.z, pt2.z)));
//	printf("1 = %lf\n", fdf->diff);
	line(fdf, &pt1, &pt3, ft_color(fdf, ft_intmax(pt1.z, pt3.z)));
}

int			ft_draw(t_fdf *fdf)
{
	int			x;
	int			y;

	x = 0;
	if (fdf->draw == 1)
		ft_new_image(fdf);
	while (x < fdf->x - 1)
	{
		y = 0;
		while(y <= fdf->y - 1)
		{
//			ft_print_tout(fdf, fdf->map[x][y]);
			square(fdf, made_pts(x, y, fdf->map[x][y]), \
						made_pts(x + 1, y, fdf->map[x + 1][y]), \
						made_pts(x, y + 1, fdf->map[x][y + 1]));
			square(fdf, made_pts(x + 1, y + 1, fdf->map[x + 1][y + 1]), \
						made_pts(x + 1, y , fdf->map[x + 1][y]), \
						made_pts(x, y + 1, fdf->map[x][y + 1]));
			y++;
		}
		x++;
	}
	fdf->draw = 1;
	mlx_put_image_to_window(fdf->mlx, fdf->win1, fdf->img, 0, 0);
	ft_display(fdf);
	return (0);
}
