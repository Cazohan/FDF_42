/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lherbelo <lherbelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 15:08:19 by lherbelo          #+#    #+#             */
/*   Updated: 2016/04/12 14:13:24 by lherbelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

void		ft_init_fdf(t_fdf *fdf)
{
	if ((fdf->mlx = mlx_init()) == NULL)
		ft_error("Init fail\n");
	fdf->win1 = mlx_new_window(fdf->mlx, fdf->widght, fdf->height, "FdF");
	fdf->img = mlx_new_image(fdf->mlx, fdf->widght, fdf->height);
	fdf->addr = mlx_get_data_addr(fdf->img, &(fdf->bpp), &(fdf->s_l),\
								&(fdf->end));
}

void		ft_init(t_fdf *fdf, int ac, char **av)
{
	if (ac == 2)
	{
		fdf->widght = WIDTH;
		fdf->height = HEIGHT;
		ft_init_fdf(fdf);
	}
	else if (ac == 4)
	{
		fdf->height = ft_atoi(av[2]);
		fdf->widght = ft_atoi(av[3]);
		ft_init_fdf(fdf);
	}
	else
		ft_error("./fdf use only one .fdf file and maybe x and y coord,\n");
}
