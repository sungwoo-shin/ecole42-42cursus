/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:27:28 by sshin             #+#    #+#             */
/*   Updated: 2022/02/23 20:46:30 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotate_x(int *y, int *z, double alpha)
{
	int	prev_y;

	prev_y = *y;
	*y = prev_y * cos(alpha) + (*z) * sin(alpha);
	*z = -prev_y * sin(alpha) + (*z) * cos(alpha);
}

static void	rotate_y(int *x, int *z, double beta)
{
	int	prev_x;

	prev_x = *x;
	*x = prev_x * cos(beta) + (*z) * sin(beta);
	*z = -prev_x * sin(beta) + (*z) * cos(beta);
}

static void	rotate_z(int *x, int *y, double gamma)
{
	int	prev_x;
	int	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = prev_x * cos(gamma) - prev_y * sin(gamma);
	*y = prev_x * sin(gamma) + prev_y * cos(gamma);
}

/*
** 30deg × π/180 = 0.5236rad
*/

static void	conv_to_iso(int *x, int *y, int z)
{
	int	prev_x;
	int	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(0.5236);
	*y = (prev_x + prev_y) * sin(0.5236) - z;
}

/*
** Project a point
** 1. Camera zoom transformation
** 2. Translation: world focus to world origin
** 3. Rotation transformation
** 4. Translation: world origin to screen center
** 5. Calibration: p.y += fdf->map->height * fdf->camera->zoom * 2 / 5
*/

t_point	*project_point(t_point *p, t_fdf *fdf)
{
	p->x *= fdf->camera->zoom;
	p->y *= fdf->camera->zoom;
	p->z *= fdf->camera->zoom / fdf->camera->z_divisor;
	p->x -= (fdf->map->width * fdf->camera->zoom) / 2;
	p->y -= (fdf->map->height * fdf->camera->zoom) / 2;
	rotate_x(&(p->y), &(p->z), fdf->camera->alpha);
	rotate_y(&(p->x), &(p->z), fdf->camera->beta);
	rotate_z(&(p->x), &(p->y), fdf->camera->gamma);
	if (fdf->camera->projection == ISOMETRIC)
		conv_to_iso(&(p->x), &(p->y), (p->z));
	p->x += (SCRN_WIDTH - SUB_SCRN_WIDTH) / 2 + SUB_SCRN_WIDTH + \
			fdf->camera->x_offset;
	p->y += SCRN_HEIGHT / 2 + fdf->camera->y_offset;
	p->y += fdf->map->height * fdf->camera->zoom * 2 / 5;
	return (p);
}
