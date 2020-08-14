/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstench <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 17:32:36 by sstench           #+#    #+#             */
/*   Updated: 2020/08/12 17:32:38 by sstench          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		check_win_size(int key, t_trace **matrix)
{
	if ((key == 0 && PRM.win_height <= 500) ||\
		(key == 6 && PRM.win_width <= 500))
		return (1);
	if ((key == 1 && PRM.win_height > 1000) ||\
		(key == 7 && PRM.win_width > 2000))
		return (1);
	return (0);
}

void	full_screen(t_trace **matrix)
{
	static int old_x;
	static int old_y;

	if (PRM.win_width != 2560)
	{
		old_x = PRM.win_width;
		old_y = PRM.win_width;
	}
	PRM.win_width = (PRM.win_width == 2560) ? old_x : 2560;
	PRM.win_height = (PRM.win_height == 1400) ? old_y : 1400;
}

void	change_window_size(int key, t_trace **matrix)
{
	if (check_win_size(key, matrix))
		return ;
	if (key == 6)
		PRM.win_width -= 100;
	if (key == 7)
		PRM.win_width += 100;
	if (key == 0)
		PRM.win_height -= 100;
	if (key == 1)
		PRM.win_height += 100;
	if (key == 3)
		full_screen(matrix);
}

void	new_window(int key, t_trace **matrix)
{
	change_window_size(key, matrix);
	mlx_destroy_window(PRM.mlx_ptr, PRM.win_ptr);
	PRM.mlx_ptr = mlx_init();
	PRM.win_ptr = \
	mlx_new_window(PRM.mlx_ptr, PRM.win_width, PRM.win_height, "FDF");
	PRM.shift_x = PRM.win_width / 2.8;
	PRM.shift_y = PRM.win_height / 2.8;
	draw_map(matrix);
	mlx_key_hook(PRM.win_ptr, deal_key, matrix);
	mlx_loop(PRM.mlx_ptr);
}
