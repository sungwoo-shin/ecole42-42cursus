/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:27:28 by sshin             #+#    #+#             */
/*   Updated: 2021/08/18 17:02:59 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "key_macos.h"

/*
** <Controls>
** MB1 & Drag: Rotate
** MB2 & MB3 & Drag: Translate
** Scroll: Zoom in/out
** Key X/Y/Z: Rotate around x/y/z
** key I/P: Isometric/Parallel
** Key +/-: Flatten
*/

static void	zoom(int key, t_fdf *fdf)
{
	if (key == MB2_UP)
		++(fdf->camera->zoom);
	else if (key == MB2_DOWN)
		--(fdf->camera->zoom);
	if (fdf->camera->zoom < 1)
		fdf->camera->zoom = 1;
	draw_fdf(fdf->map, fdf);
}

static int	mouse_press(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	(void)x;
	(void)y;
	fdf = (t_fdf *)param;
	if (button == MB2_UP || button == MB2_DOWN)
		zoom(button, fdf);
	else if (button == MB1)
		fdf->mouse->flag_mb1_pressed = true;
	else if (button == MB2)
		fdf->mouse->flag_mb2_pressed = true;
	else if (button == MB3)
		fdf->mouse->flag_mb3_pressed = true;
	return (0);
}

static int	mouse_release(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	(void)x;
	(void)y;
	(void)button;
	fdf = (t_fdf *)param;
	fdf->mouse->flag_mb2_pressed = false;
	fdf->mouse->flag_mb3_pressed = false;
	return (0);
}

static int	mouse_move(int cur_x, int cur_y, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	fdf->mouse->prev_x = fdf->mouse->cur_x;
	fdf->mouse->prev_y = fdf->mouse->cur_y;
	fdf->mouse->cur_x = cur_x;
	fdf->mouse->cur_y = cur_y;
	if (fdf->mouse->flag_mb2_pressed && fdf->mouse->flag_mb3_pressed)
	{
		fdf->camera->x_offset += (cur_x - fdf->mouse->prev_x);
		fdf->camera->y_offset += (cur_y - fdf->mouse->prev_y);
	}
	else if (fdf->mouse->flag_mb2_pressed)
	{
		fdf->camera->beta += (cur_x - fdf->mouse->prev_x) * 0.002;
		fdf->camera->alpha += (cur_y - fdf->mouse->prev_y) * 0.002;
	}
	draw_fdf(fdf->map, fdf);
	return (0);
}

/*
** X11 Events
** 02: keyPress
** 04: ButtonPress
** 05: ButtonRelease
** 06: MotionNotify
** 17: DestroyNotify
**
** x_mask is ignored on macOS
** https://stackoverflow.com/c/42network/questions/164
*/

void	set_cntl(t_fdf *fdf)
{
	mlx_hook(fdf->win, 4, 0L, mouse_press, fdf);
	mlx_hook(fdf->win, 5, 0L, mouse_release, fdf);
	mlx_hook(fdf->win, 6, 0L, mouse_move, fdf);
	mlx_hook(fdf->win, 2, 0L, key_press, fdf);
	mlx_hook(fdf->win, 17, 0L, quit, fdf);
}
