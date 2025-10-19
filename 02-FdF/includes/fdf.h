/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:27:28 by sshin             #+#    #+#             */
/*   Updated: 2021/08/21 15:35:06 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <errno.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdbool.h>
# include "mlx.h"
# include "math.h"
# include "libft.h"
# include "get_next_line.h"

# define SCRN_HEIGHT		1050
# define SCRN_WIDTH			1400
# define SUB_SCRN_WIDTH		330

# define CLR_TEXT			0xEAEAEA
# define CLR_MAIN_SCRN_BG	0x222222
# define CLR_SUB_SCRN_BG	0x1E1E1E
# define CLR_DISCO			0x9A1F6A
# define CLR_BRICK_RED		0xC2294E
# define CLR_FLAMINGO		0xEC4B27
# define CLR_JAFFA			0xEF8633
# define CLR_SAFFRON		0xF3AF3D

typedef struct s_node
{
	int				z;
	int				clr;
	struct s_node	*nxt;
}				t_node;

typedef struct s_map
{
	int				width;
	int				height;
	int				*arr_z;
	int				*arr_clr;
	int				z_min;
	int				z_max;
}				t_map;

typedef struct s_point
{
	int				x;
	int				y;
	int				z;
	int				clr;
}				t_point;

typedef enum e_projection
{
	ISOMETRIC,
	PARALLEL
}	t_projection;

typedef struct s_camera
{
	t_projection	projection;
	double			alpha;
	double			beta;
	double			gamma;
	int				x_offset;
	int				y_offset;
	int				zoom;
	float			z_divisor;
}				t_camera;

typedef struct s_mouse
{
	bool			flag_mb1_pressed;
	bool			flag_mb2_pressed;
	bool			flag_mb3_pressed;
	int				cur_x;
	int				cur_y;
	int				prev_x;
	int				prev_y;
}				t_mouse;

typedef struct s_fdf
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data_addr;
	int				bpp;
	int				size_line;
	int				endian;
	t_map			*map;
	t_camera		*camera;
	t_mouse			*mouse;
}				t_fdf;

/* init.c
** =============================================================================
*/
t_fdf		*init_fdf(t_map *map);
t_camera	*init_camera(t_fdf *fdf);
t_point		*init_point(int x, int y, t_map *map);

/* draw.c
** =============================================================================
*/
void		draw_fdf(t_map *map, t_fdf *fdf);

/* project.c
** =============================================================================
*/
t_point		*project_point(t_point *p, t_fdf *fdf);

/* color.c
** =============================================================================
*/
int			get_default_clr(int z, t_map *map);
int			get_clr(t_point cur, t_point *s, t_point *f, t_point delta);

/* mouse.c
** =============================================================================
*/
void		set_cntl(t_fdf *fdf);

/* key.c
** =============================================================================
*/
int			key_press(int key, void *param);
int			quit(void *param);

/* utils.c
** =============================================================================
*/
void		terminate(char *str);
void		push_node(t_node **stack, t_node *new_node);
t_node		*pop_node(t_node **stack);
void		print_controls(t_fdf *fdf);
void		print_status(t_fdf *fdf);

#endif
