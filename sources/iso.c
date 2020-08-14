/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstench <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 16:34:01 by sstench           #+#    #+#             */
/*   Updated: 2020/08/12 16:35:37 by sstench          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(t_trace *dot, double angle)
{
	dot->width = (dot->width - dot->height) * cos(angle);
	dot->height = (dot->width + dot->height) * sin(angle) - dot->length;
}
