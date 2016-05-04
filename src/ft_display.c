/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lherbelo <lherbelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 20:19:03 by lherbelo          #+#    #+#             */
/*   Updated: 2016/05/04 15:04:09 by lherbelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void		ft_display(t_fdf *fdf)
{
	if (fdf->screen == 0)
	{
		mlx_string_put(fdf->mlx, fdf->win1, 10, 10, BLANC, ARROW1);
		mlx_string_put(fdf->mlx, fdf->win1, 10, 25, BLANC, ZOOM1);
		mlx_string_put(fdf->mlx, fdf->win1, 10, 40, BLANC, RELIEF1);
		mlx_string_put(fdf->mlx, fdf->win1, 10, 55, BLANC, ECHAP1);
		mlx_string_put(fdf->mlx, fdf->win1, 10, 70, BLANC, CENTER);
		mlx_string_put(fdf->mlx, fdf->win1, 10, 85, BLANC, HIDE1);
	}
	if (fdf->screen == 1)
		mlx_string_put(fdf->mlx, fdf->win1, 10, 10, BLANC, HIDE2);
}
