/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:27:28 by sshin             #+#    #+#             */
/*   Updated: 2021/08/22 14:14:20 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_background(t_fdf *fdf)
{
	int	i;
	int	*img;

	i = 0;
	img = (int *)(fdf->data_addr);
	while (i < SCRN_HEIGHT * SCRN_WIDTH)
	{
		if (i % SCRN_WIDTH < SUB_SCRN_WIDTH)
			img[i] = CLR_SUB_SCRN_BG;
		else
			img[i] = CLR_MAIN_SCRN_BG;
		++i;
	}
}

/*
** bits per pixel: 32(4 bytes; int)
** size_line: 4000
*/

static void	put_pixel(t_fdf *fdf, int x, int y, int clr)
{
	int	i;

	if ((SUB_SCRN_WIDTH <= x && x < SCRN_WIDTH) && \
		(0 <= y && y < SCRN_HEIGHT))
	{
		i = (x * fdf->bpp / 8) + (y * fdf->size_line);
		fdf->data_addr[i] = clr;
		fdf->data_addr[++i] = clr >> 8;
		fdf->data_addr[++i] = clr >> 16;
	}
}

/*
** Optimized Bresenham's line drawing algorithm
**
** plotLine(int x0, int y0, int x1, int y1)
**     dx =  abs(x1-x0);
**     sx = x0<x1 ? 1 : -1;
**     dy = -abs(y1-y0);
**     sy = y0<y1 ? 1 : -1;
**     err = dx+dy;  // error value e_xy
**     while (true)   // loop
**         plot(x0, y0);
**         if (x0 == x1 && y0 == y1) break;
**         e2 = 2*err;
**         if (e2 >= dy) // e_xy+e_x > 0
**             err += dy;
**             x0 += sx;
**         end if
**         if (e2 <= dx) // e_xy+e_y < 0
**             err += dx;
**             y0 += sy;
**         end if
**     end while
*/

static void	init_delta_and_step(t_point *s, t_point *f, \
		t_point *delta, t_point *step)
{
	delta->x = GET_ABS(f->x - s->x);
	delta->y = GET_ABS(f->y - s->y);
	if (s->x < f->x)
		step->x = 1;
	else
		step->x = -1;
	if (s->y < f->y)
		step->y = 1;
	else
		step->y = -1;
}

static void	draw_line(t_point *s, t_point *f, t_fdf *fdf)
{
	t_point	delta;
	t_point	step;
	t_point	cur;
	int		err[2];

	init_delta_and_step(s, f, &delta, &step);
	err[0] = delta.x - delta.y;
	cur = *s;
	while (cur.x != f->x || cur.y != f->y)
	{
		put_pixel(fdf, cur.x, cur.y, get_clr(cur, s, f, delta));
		err[1] = err[0] * 2;
		if (err[1] < delta.x)
		{
			err[0] += delta.x;
			cur.y += step.y;
		}
		if (err[1] > -delta.y)
		{
			err[0] -= delta.y;
			cur.x += step.x;
		}
	}
	free(s);
	s = NULL;
	free(f);
	f = NULL;
}

void	draw_fdf(t_map *map, t_fdf *fdf)
{
	int	x;
	int	y;

	draw_background(fdf);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x < fdf->map->width - 1)
			{
				draw_line(project_point(init_point(x, y, map), fdf), \
						project_point(init_point(x + 1, y, map), fdf), fdf);
			}
			if (y < fdf->map->height - 1)
				draw_line(project_point(init_point(x, y, map), fdf), \
						project_point(init_point(x, y + 1, map), fdf), fdf);
			++x;
		}
		++y;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	print_controls(fdf);
	print_status(fdf);
}
