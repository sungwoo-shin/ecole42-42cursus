/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:27:28 by sshin             #+#    #+#             */
/*   Updated: 2021/08/18 16:43:45 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	*init_fdf(t_map *map)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf) * 1);
	if (fdf == NULL)
		terminate("fdf initialization error");
	fdf->mlx = mlx_init();
	if (fdf->mlx == NULL)
		terminate("fdf initialization error");
	fdf->win = mlx_new_window(fdf->mlx, SCRN_WIDTH, SCRN_HEIGHT, "FdF");
	if (fdf->win == NULL)
		terminate("fdf initialization error");
	fdf->img = mlx_new_image(fdf->mlx, SCRN_WIDTH, SCRN_HEIGHT);
	if (fdf->img == NULL)
		terminate("fdf initialization error");
	fdf->data_addr = mlx_get_data_addr(fdf->img, &(fdf->bpp),
			&(fdf->size_line), &(fdf->endian));
	fdf->map = map;
	fdf->mouse = (t_mouse *)malloc(sizeof(t_mouse) * 1);
	if (fdf->mouse == NULL)
		terminate("fdf initialization error");
	return (fdf);
}

t_camera	*init_camera(t_fdf *fdf)
{
	t_camera	*camera;

	camera = (t_camera *)malloc(sizeof(t_camera) * 1);
	if (camera == NULL)
		terminate("camera initialization error");
	camera->alpha = 0;
	camera->beta = 0;
	camera->gamma = 0;
	camera->x_offset = 0;
	camera->y_offset = 0;
	camera->zoom = \
			GET_LESS((SCRN_WIDTH - SUB_SCRN_WIDTH) / fdf->map->width / 2,
			SCRN_HEIGHT / fdf->map->height / 2);
	camera->z_divisor = 1;
	return (camera);
}

t_point	*init_point(int x, int y, t_map *map)
{
	t_point	*point;
	int		i;

	point = (t_point *)malloc(sizeof(t_point) * 1);
	if (point == NULL)
		terminate("point initialization error");
	point->x = x;
	point->y = y;
	i = y * map->width + x;
	point->z = (map->arr_z)[i];
	if ((map->arr_clr)[i] == -1)
		point->clr = get_default_clr(point->z, map);
	else
		point->clr = map->arr_clr[i];
	return (point);
}
