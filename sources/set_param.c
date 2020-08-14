/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstench <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 16:23:24 by sstench           #+#    #+#             */
/*   Updated: 2020/08/12 16:23:26 by sstench          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom(t_trace *a, t_trace *b, t_trace *param)
{
	a->width *= param->scale;
	a->height *= param->scale;
	a->length *= param->z_scale;
	b->width *= param->scale;
	b->height *= param->scale;
	b->length *= param->z_scale;
}

void	set_param(t_trace *a, t_trace *b, t_trace *param)
{
	zoom(a, b, param);
	if (param->is_isometric)
	{
		isometric(a, param->angle);
		isometric(b, param->angle);
	}
	a->width += param->shift_x;
	a->height += param->shift_y;
	b->width += param->shift_x;
	b->height += param->shift_y;
}
