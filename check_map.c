/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 08:14:13 by schiou            #+#    #+#             */
/*   Updated: 2023/09/06 15:11:59 by schiou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void	is_rectanglar(t_data *data);
void	is_surrounded_by_wall(t_data *data);
void	is_valid_char(t_data *data);
int		is_valid_num_object(t_data *data);

void	check_map(t_data *data)
{
	is_rectanglar(data);
	is_surrounded_by_wall(data);
	is_valid_char(data);
	if (!is_valid_num_object(data))
		free_map_data_with_error(data, "Invalid number of objects");
}

//get map width and check each line of length
//if one of line lenght is not eaual to width, error
void	is_rectanglar(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	data->width = ft_strlen(data->map_data[0]) - 1;
	while (y < data->height)
	{
		if (ft_strlen(data->map_data[y]) - 1 != (size_t)data->width)
			free_map_data_with_error(data, "Map is not rectanglar");
		y++;
	}
}

//Check top row and bottom row
//Check first column and last column
void	is_surrounded_by_wall(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < data->width)
	{
		if (!(data->map_data[0][x] == '1'
			&& data->map_data[data->height - 1][x] == '1'))
			free_map_data_with_error(data, "Map is not surrounded by wall");
		x++;
	}
	y = 0;
	while (y < data->height)
	{
		if (!(data->map_data[y][0] == '1'
			&& data->map_data[y][data->width - 1] == '1'))
			free_map_data_with_error(data, "Map is not surrounded by wall");
		y++;
	}
}

//Loop through 2D array and get each element 
//If one of element is not from "10EPC", error
//Also counting exit number, player number and coin number
void	is_valid_char(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map_data[y])
	{
		x = 0;
		while (x < data->width)
		{
			if (ft_strchr("10EPC", data->map_data[y][x]) == NULL)
				free_map_data_with_error(data, "Invalid character exist");
			if (data->map_data[y][x] == 'E')
				data->num_exit++;
			if (data->map_data[y][x] == 'P')
			{
				data->num_player++;
				data->player_y = y;
				data->player_x = x;
			}
			if (data->map_data[y][x] == 'C')
				data->num_coin++;
			x++;
		}
		y++;
	}
}

int	is_valid_num_object(t_data *data)
{
	if (data->num_exit == 1 && data->num_player == 1 && data->num_coin > 0)
		return (1);
	return (0);
}
