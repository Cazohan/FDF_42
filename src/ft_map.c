/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lherbelo <lherbelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 19:39:39 by lherbelo          #+#    #+#             */
/*   Updated: 2016/05/04 15:57:14 by lherbelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_coord		*coord(int x, int y, int z)
{
	t_coord	*coord;

	coord = (t_coord *)ft_memalloc(sizeof(t_coord));
	coord->x = x;
	coord->y = y;
	coord->z = z;
	return (coord);
}

void		lst_map(t_fdf *fdf, t_list *pts, int x, int y)
{
	int		i;
	int		**map;
	t_list	*pouet;
	t_coord	*coords;

	i = 0;
	pouet = pts;
	map = (int **)ft_memalloc(sizeof(int *) * x);
	while (i < x)
	{
		map[i] = (int *)ft_memalloc(sizeof(int *) * y);
		i++;
	}
	while (pouet)
	{
		coords = pouet->content;
		if (coords->x < x && coords->y < y)
			map[coords->x][coords->y] = coords->z;
		pouet = pouet->next;
	}
	fdf->map = map;
	fdf->zoom = 360 / (x + y);
	fdf->xpos = x * fdf->zoom * 1.3;
	fdf->ypos = y * fdf->zoom * 1.2;
	fdf->relief = 0.5;
}

void		read_map(t_fdf *fdf, int fd)
{
	int		i;
	int		j;
	t_list	*pts;
	char	*line;
	char	**tmp;

	i = 0;
	while (get_next_line(fd, &line))
	{
		j = 0;
		tmp = ft_strsplit(line, ' ');
		while (tmp[j] != NULL)
		{
			ft_set_color(fdf, ft_atoi(tmp[j]));
//			printf("diff = %lf\n", fdf->diff);
			ft_lstadd(&pts, ft_lstnew(coord(j, i, ft_atoi(tmp[j])),\
									sizeof(t_coord)));
			j++;
		}
		i++;
	}
	fdf->x = j;
	fdf->y = i;
	lst_map(fdf, pts, j, i);
}
