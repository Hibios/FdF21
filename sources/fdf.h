/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstench <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 10:54:26 by sstench           #+#    #+#             */
/*   Updated: 2020/08/12 19:03:59 by sstench          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include <math.h>
# include "../minilibx_macos/mlx.h"
# define PRM matrix[0][0]
# define ABS(A) ((A < 0) ? -A : A)

typedef struct
{
	float	width;
	float	height;
	float	length;
	int		is_last;
	int		scale;
	int		z_scale;
	double	angle;
	int		shift_x;
	int		shift_y;
	int		is_isometric;
	int		win_width;
	int		win_height;
	void	*mlx_ptr;
	void	*win_ptr;
}			t_trace;

t_trace		**read_map(char *file_name);
void		ft_error(char *msg);
void		draw_map(t_trace **matrix);
int			deal_key(int key, t_trace **matrix);
void		isometric(t_trace *dot, double angle);
void		set_param(t_trace *a, t_trace *b, t_trace *param);
void		new_window(int key, t_trace **matrix);

#endif
