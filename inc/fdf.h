/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lherbelo <lherbelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 14:48:01 by lherbelo          #+#    #+#             */
/*   Updated: 2016/08/17 12:57:04 by lherbelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "libft.h"
#include "mlx.h"
#include <fcntl.h>
# define WIDTH 1200
# define HEIGHT 800
# define BLEU 0x2C75FF
# define VIOLET 0x660099
# define ROUGE 0xFF0000
# define BLANC 0x0FFFFFF
# define JAUNE 0x0FFFF00
# define VERT 0x000FF00
# define ORANGE 0x0ED7F10
# define CYAN 0x000FFFF
# define MARRON 0x0582900
# define MAUVE 0x0D473D4
# define SAFRAN 0x0F3D617
# define VERT_F 0x0175732
# define ROUGE_F 0x06D071A
# define ROSE 0x0FD6C9E
# define ARROW1 "Put arrow to move"
# define ZOOM1 "Put page up/down to zoom"
# define RELIEF1 "Put +/- to change relief"
# define ECHAP1 "Press Echap for quit"
# define HIDE1 "Press 'H' to hide help"
# define CENTER "Press 'R' recover map"
# define HIDE2 "Press 'H' to show help"


typedef struct		s_fdf
{
	void			*mlx; /* mlx_ptr*/
	void			*win1; /* win_ptr */
	int				widght;
	int				height;
	int				**map; /*double tableau avec les coord */
	void			*img; /* ptr image */
	char			*addr; /* addr img*/
	int				bpp; /*bits per pixel*/
	int				s_l; /* size line*/
	int				end; /*endian machine*/
	int				x; /* x max */
	int				xpos; /* position x */
	int				y; /* y max */
	int				ypos; /* postion y */
	double			zoom;
	double			relief;
	int				draw;
	int				max;
	int				min;
	double			diff;
	int				screen;
}					t_fdf;

typedef struct		s_coord
{
	int				x;
	int				y;
	int				z;
}					t_coord;

int					ft_key_hook_1(int keycode, t_fdf *fdf);
char				ft_error(char *str);
void				read_map(t_fdf *fdf, int fd);
void				ft_init(t_fdf *fdf, int ac, char **av);
int					ft_draw(t_fdf *fdf);
void				put_img(t_fdf *fdf, int x, int y, int color);
void				verti(t_fdf *fdf, t_coord *pt1, t_coord *pt2, int color);
void				hori(t_fdf *fdf, t_coord *pt1, t_coord *pt2, int color);
void				ft_new_image(t_fdf *fdf);
int				ft_color(t_fdf *fdf, int z);
int				ft_set_color(t_fdf *fdf, int pt1);
void			ft_display(t_fdf *fdf);

#endif
