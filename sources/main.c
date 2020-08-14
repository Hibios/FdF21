/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstench <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 16:05:48 by sstench           #+#    #+#             */
/*   Updated: 2020/08/11 16:05:50 by sstench          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_dstate(t_trace *param)
{
	param->scale = 30;
	param->z_scale = 1;
	param->is_isometric = 1;
	param->angle = 0.523599;
	param->win_width = 1280;
	param->win_height = 720;
	param->shift_x = param->win_width / 2.8;
	param->shift_y = param->win_height / 2.8;
	param->mlx_ptr = mlx_init();
	param->win_ptr = mlx_new_window(param->mlx_ptr, \
	param->win_width, param->win_height, "FDF");
}

int		main(int argc, char **argv)
{
	t_trace **matrix;

	if (argc != 2)
		ft_error("Usage: ./fdf <map name>.fdf");
	matrix = read_map(argv[1]);
	set_dstate(&PRM);
	draw_map(matrix);
	mlx_key_hook(PRM.win_ptr, deal_key, matrix);
	mlx_loop(PRM.mlx_ptr);
}
