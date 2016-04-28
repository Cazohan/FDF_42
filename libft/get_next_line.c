/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lherbelo <lherbelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 01:10:18 by lherbelo          #+#    #+#             */
/*   Updated: 2016/02/29 17:59:01 by lherbelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int			ft_lire(t_gnl *gnl, int fd)
{
	int				i;

	i = 0;
	while (gnl->line[fd][i] != '\n' && gnl->line[fd][i] != '\0')
		i++;
	return (i);
}

static	void		ft_saveline(t_gnl *gnl, int fd)
{
	if (gnl->line[fd] == NULL)
		gnl->line[fd] = ft_strnew(1);
	while (!(ft_strchr(gnl->line[fd], '\n')) &&
		(gnl->nb = read(fd, gnl->buff, BUFF_SIZE)) > 0)
	{
		gnl->buff[gnl->nb] = '\0';
		gnl->tmp = gnl->line[fd];
		gnl->line[fd] = ft_strjoin(gnl->line[fd], gnl->buff);
		ft_strdel(&gnl->tmp);
	}
	ft_strdel(&gnl->buff);
}

int				get_next_line(int const fd, char **line)
{
	static	t_gnl	gnl;

	if (fd < 0 || line == NULL || fd > MAX_FD || 
		!(gnl.buff = (char *)ft_memalloc(sizeof(char) * BUFF_SIZE + 1)))
		return (-1);
	ft_saveline(&gnl, fd);
	if (gnl.nb == -1)
		return (-1);
	*line = ft_strsub(gnl.line[fd], 0, ft_lire(&gnl, fd));
	if (ft_strchr(gnl.line[fd], '\n'))
	{
		gnl.tmp = gnl.line[fd];
		gnl.line[fd] = ft_strdup(ft_strchr(gnl.line[fd], '\n') + 1);
		ft_strdel(&gnl.tmp);
		return(1);
	}
	if (ft_lire(&gnl, fd) > 0)
	{
		gnl.line[fd] = gnl.line[fd] + ft_lire(&gnl, fd);
		return (1);
	}
	return (0);
}
