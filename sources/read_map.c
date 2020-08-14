/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstench <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 09:53:03 by sstench           #+#    #+#             */
/*   Updated: 2020/08/12 09:53:07 by sstench          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <string.h>

int		get_line_dots(char *line, t_trace **dots, int height)
{
	char	**str_dots;
	int		width;

	str_dots = ft_strsplit(line, ' ');
	width = 0;
	while (str_dots[width])
	{
		dots[height][width].length = ft_atoi(str_dots[width]);
		dots[height][width].width = width;
		dots[height][width].height = height;
		dots[height][width].is_last = 0;
		free(str_dots[width++]);
	}
	free(str_dots);
	free(line);
	dots[height][--width].is_last = 1;
	return (width);
}

t_trace	**memory_allocete(char *file_name)
{
	int		fd;
	char	*line;
	int		width;
	int		height;
	t_trace	**new;

	if ((fd = open(file_name, O_RDONLY, 0)) <= 0)
		ft_error("File does not exists!");
	get_next_line(fd, &line);
	width = ft_elemcounter(line, ' ');
	free(line);
	height = 0;
	while (get_next_line(fd, &line) > 0)
	{
		height++;
		free(line);
	}
	new = (t_trace **)malloc(sizeof(t_trace *) * (++height + 1));
	while (height > 0)
		new[--height] = (t_trace *)malloc(sizeof(t_trace) * (width + 1));
	close(fd);
	return (new);
}

t_trace	**read_map(char *file_name)
{
	t_trace	**dots;
	int		fd;
	int		height;
	char	*line;

	dots = memory_allocete(file_name);
	fd = open(file_name, O_RDONLY, 0);
	height = 0;
	while (get_next_line(fd, &line) > 0)
		get_line_dots(line, dots, height++);
	dots[height] = NULL;
	close(fd);
	return (dots);
}
