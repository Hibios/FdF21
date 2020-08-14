/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstench <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 13:06:58 by sstench           #+#    #+#             */
/*   Updated: 2020/08/12 13:07:01 by sstench          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_trace a, t_trace b, t_trace *param)
{
	float	step_x;
	float	step_y;
	float	max;
	int		color;

	set_param(&a, &b, param);
	step_x = b.width - a.width;
	step_y = b.height - a.height;
	max = MAX(ABS(step_x), ABS(step_y));
	step_x /= max;
	step_y /= max;
	color = (b.length || a.length) ? 3066993 : 15528177;
	color = (b.length != a.length) ? 1752220 : color;
	while ((int)(a.width - b.width) || (int)(a.height - b.height))
	{
		mlx_pixel_put(param->mlx_ptr, param->win_ptr, a.width, a.height, color);
		a.width += step_x;
		a.height += step_y;
		if (a.width > param->win_width || a.height > param->win_height || \
		a.height < 0 || a.width < 0)
			break ;
	}
}

void	draw_map(t_trace **matrix)
{
	int	width;
	int	height;

	height = 0;
	while (matrix[height])
	{
		width = 0;
		while (1)
		{
			if (matrix[height + 1])
				draw_line(matrix[height][width], \
				matrix[height + 1][width], &PRM);
			if (!matrix[height][width].is_last)
				draw_line(matrix[height][width], \
				matrix[height][width + 1], &PRM);
			if (matrix[height][width].is_last)
				break ;
			width++;
		}
		height++;
	}
}
