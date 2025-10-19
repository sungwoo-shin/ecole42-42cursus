/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:27:28 by sshin             #+#    #+#             */
/*   Updated: 2021/08/22 14:15:51 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_node	*create_node(char *splited_line)
{
	t_node	*new_node;
	char	**buf;

	new_node = (t_node *)malloc(sizeof(t_node) * 1);
	if (new_node == NULL)
		terminate("Map reading error");
	buf = split_into_strs(splited_line, ',');
	if (buf == NULL)
		terminate("Map reading error");
	new_node->z = ft_atoi(buf[0]);
	if (buf[1])
		new_node->clr = atoi_base(buf[1], 16);
	else
		new_node->clr = -1;
	new_node->nxt = NULL;
	double_free(buf);
	return (new_node);
}

static void	init_stack(t_node **stack, t_map *map, char **splited_line)
{
	int	width;

	width = 0;
	while (*splited_line)
	{
		push_node(stack, create_node(*splited_line));
		++width;
		++splited_line;
	}
	if (map->height == 0)
		map->width = width;
}

static void	read_map(char **argv, t_node **stack, t_map *map)
{
	int		fd;
	int		ret_gnl;
	char	*line;
	char	**splited_line;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || OPEN_MAX <= fd)
		terminate("Map reading error");
	ret_gnl = get_next_line(fd, &line);
	while (ret_gnl == 1)
	{
		splited_line = split_into_strs(line, ' ');
		if (splited_line == NULL)
			terminate("Map reading error");
		init_stack(stack, map, splited_line);
		double_free(splited_line);
		++(map->height);
		free(line);
		line = NULL;
		ret_gnl = get_next_line(fd, &line);
	}
	free(line);
	line = NULL;
	if (ret_gnl == -1)
		terminate("Map reading error");
}

static void	stack_to_arr(t_node **stack, t_map *map)
{
	int		i;
	t_node	*buf;

	map->arr_z = (int *)malloc(map->width * map->height * sizeof(int));
	if (map->arr_z == NULL)
		terminate("Conversion to array error");
	map->arr_clr = (int *)malloc(map->width * map->height * sizeof(int));
	if (map->arr_clr == NULL)
		terminate("Conversion to array error");
	i = map->width * map->height - 1;
	while (i >= 0)
	{
		buf = pop_node(stack);
		map->arr_z[i] = buf->z;
		map->arr_clr[i] = buf->clr;
		if (buf->z > map->z_max)
			map->z_max = buf->z;
		if (buf->z < map->z_min)
			map->z_min = buf->z;
		free(buf);
		buf = NULL;
		--i;
	}
}

int	main(int argc, char **argv)
{
	t_node	*stack;
	t_map	map;
	t_fdf	*fdf;

	errno = 0;
	if (argc != 2)
		terminate("Execution error\nUsage: ./fdf MAP_FILE");
	stack = NULL;
	map = (t_map){0, };
	read_map(argv, &stack, &map);
	stack_to_arr(&stack, &map);
	fdf = init_fdf(&map);
	fdf->camera = init_camera(fdf);
	draw_fdf(&map, fdf);
	set_cntl(fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
