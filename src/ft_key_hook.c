/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lherbelo <lherbelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 13:39:32 by lherbelo          #+#    #+#             */
/*   Updated: 2016/08/17 12:55:58 by lherbelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_new_image(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx, fdf->img);
	fdf->img = mlx_new_image(fdf->mlx, fdf->widght, fdf->height);
	fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->s_l, &fdf->end);
}

void	ft_echap(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx, fdf->img);
	mlx_destroy_window(fdf->mlx, fdf->win1);
	exit(0);
}

void	ft_move(int keycode, t_fdf *fdf)
{
	if (keycode == 124)
		fdf->xpos += 10;
	if (keycode == 123)
		fdf->xpos -= 10;
	if (keycode == 126)
		fdf->ypos -= 10;
	if (keycode == 125)
		fdf->ypos += 10;
	if (keycode == 69 || keycode == 24)
		fdf->relief += 0.25;
	if (keycode == 78 || keycode == 27)
		fdf->relief -= 0.25;
	if (keycode == 116)
		fdf->zoom *= 1.05;
	if (keycode == 121)
		fdf->zoom /= 1.05;
	if (keycode == 15)
	{
		fdf->xpos = fdf->widght / 2;
		fdf->ypos = fdf->height / 4;
		fdf->relief = 0.5;
		fdf->zoom = 10.0;
	}
}

int		ft_key_hook_1(int keycode, t_fdf *fdf)
{
	if (keycode == 4)
	{
		if (fdf->screen == 1)
			fdf->screen = 0;
		else
			fdf->screen = 1;
	}
	if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126 \
		|| keycode == 69 || keycode == 78 || keycode == 116 || keycode == 121 \
		|| keycode == 15 || keycode == 24 || keycode == 27)
		ft_move(keycode, fdf);
	if (keycode == 53)
		ft_echap(fdf);
	ft_draw(fdf);
	return (0);
}
