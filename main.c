/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lherbelo <lherbelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 14:55:33 by lherbelo          #+#    #+#             */
/*   Updated: 2016/04/23 14:58:12 by lherbelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

char	ft_error(char *str)
{
	ft_putstr(str);
	exit (0);
}

int		main(int ac, char **av)
{
	static t_fdf	fdf;
	int fd;

	ft_init(&fdf, ac, av);
	fd = open(av[1], O_RDONLY);
	read_map(&fdf, fd);
	mlx_expose_hook(fdf.win1, ft_draw, &fdf);
	mlx_key_hook(fdf.win1, ft_key_hook_1, &fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
