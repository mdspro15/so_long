/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 09:39:30 by schiou            #+#    #+#             */
/*   Updated: 2023/09/07 12:13:59 by schiou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void	set_file_to_image(t_data *data);
void	all_set(t_data *data);
void	set_object(t_data *data, int y, int x, char *object);

void	display_image(t_data *data)
{
	set_file_to_image(data);
	all_set(data);
}

void	set_file_to_image(t_data *data)
{
	int	img_w;
	int	img_h;

	img_w = 50;
	img_h = 50;
	data->tree = mlx_xpm_file_to_image
		(data->mlx, "xpm/ice.xpm", &img_w, &img_h);
	data->coin = mlx_xpm_file_to_image
		(data->mlx, "xpm/fish2.xpm", &img_w, &img_h);
	data->exit = mlx_xpm_file_to_image
		(data->mlx, "xpm/house.xpm", &img_w, &img_h);
	data->player = mlx_xpm_file_to_image
		(data->mlx, "xpm/penguin_right.xpm", &img_w, &img_h);
	data->path = mlx_xpm_file_to_image
		(data->mlx, "xpm/path.xpm", &img_w, &img_h);
}

void	all_set(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map_data[y])
	{
		x = 0;
		while (x < data->width)
		{
			if (data->map_data[y][x] == '1')
				set_object(data, y, x, data->tree);
			if (data->map_data[y][x] == '0')
				set_object(data, y, x, data->path);
			if (data->map_data[y][x] == 'E')
				set_object(data, y, x, data->exit);
			if (data->map_data[y][x] == 'P')
				set_object(data, y, x, data->player);
			if (data->map_data[y][x] == 'C')
				set_object(data, y, x, data->coin);
			x++;
		}
		y++;
	}
}

void	set_object(t_data *data, int y, int x, char *object)
{
	mlx_put_image_to_window(data->mlx, data->win, object, x * 50, y * 50);
}
