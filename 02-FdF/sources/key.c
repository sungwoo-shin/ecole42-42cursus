/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:27:28 by sshin             #+#    #+#             */
/*   Updated: 2021/08/21 15:35:33 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "key_macos.h"

static void	rotate(int key, t_fdf *fdf)
{
	if (key == KEY_X)
		fdf->camera->alpha += 0.03;
	else if (key == KEY_Y)
		fdf->camera->beta += 0.03;
	else if (key == KEY_Z)
		fdf->camera->gamma += 0.03;
	draw_fdf(fdf->map, fdf);
}

static void	change_projection(int key, t_fdf *fdf)
{
	fdf->camera->alpha = 0;
	fdf->camera->beta = 0;
	fdf->camera->gamma = 0;
	if (key == KEY_I)
		fdf->camera->projection = ISOMETRIC;
	else if (key == KEY_P)
		fdf->camera->projection = PARALLEL;
	draw_fdf(fdf->map, fdf);
}

static void	flatten(int key, t_fdf *fdf)
{
	if (key == KEY_EQUAL)
		fdf->camera->z_divisor -= 0.1;
	else if (key == KEY_MINUS)
		fdf->camera->z_divisor += 0.1;
	if (fdf->camera->z_divisor < 0.1)
		fdf->camera->z_divisor = 0.1;
	else if (fdf->camera->z_divisor > 7)
		fdf->camera->z_divisor = 7;
	draw_fdf(fdf->map, fdf);
}

/*
** <Controls>
** MB1 & Drag: Rotate
** MB2 & MB3 & Drag: Translate
** Scroll: Zoom in/out
** Key X/Y/Z: Rotate around x/y/z
** key I/P: Isometric/Parallel
** Key +/-: Flatten
*/

int	key_press(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (key == KEY_X || key == KEY_Y || key == KEY_Z)
		rotate(key, fdf);
	else if (key == KEY_I || key == KEY_P)
		change_projection(key, fdf);
	else if (key == KEY_EQUAL || key == KEY_MINUS)
		flatten(key, fdf);
	else if (key == KEY_ESCAPE)
		exit(0);
	return (0);
}

int	quit(void *param)
{
	(void)param;
	exit(0);
}
