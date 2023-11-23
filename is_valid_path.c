/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:37:27 by schiou            #+#    #+#             */
/*   Updated: 2023/09/06 17:05:28 by schiou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void	copy_map(t_data *data, char *file);
void	mark(t_data *data, int y, int x);
void	mark_again(t_data *data, int y, int x);

void	is_valid_path(t_data *data, char *file)
{
	int	start_y;
	int	start_x;

	start_y = data->player_y;
	start_x = data->player_x;
	copy_map(data, file);
	mark(data, start_y, start_x);
	if (!(data->copy_exit == 1 && data->copy_coin == data->num_coin))
	{
		free_copy_map(data);
		free_map_data_with_error(data, "Object must be in walkable are");
	}
	free_copy_map(data);
	copy_map(data, file);
	data->copy_coin = 0;
	mark_again(data, start_y, start_x);
	if (data->copy_coin != data->num_coin)
	{
		free_copy_map(data);
		free_map_data_with_error(data, "Coin is blocked by exit");
	}
	free_copy_map(data);
}

void	copy_map(t_data *data, char *file)
{
	int	i;
	int	fd;

	i = 0;
	data->copy = (char **)malloc(sizeof(char *) * (data->height + 1));
	if (data->copy == NULL)
	{
		perror("Error");
		exit(1);
	}
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error");
		exit(1);
	}
	while (i < data->height)
	{
		data->copy[i] = get_next_line(fd);
		i++;
	}
	data->copy[i] = NULL;
	close(fd);
}

void	mark(t_data *data, int y, int x)
{
	if (data->copy[y][x] != '1' && data->copy[y][x] != 'M')
	{
		if (data->copy[y][x] == 'C')
			data->copy_coin++;
		if (data->copy[y][x] == 'E')
			data->copy_exit++;
		data->copy[y][x] = 'M';
		mark(data, y + 1, x);
		mark(data, y - 1, x);
		mark(data, y, x + 1);
		mark(data, y, x - 1);
	}
}

void	mark_again(t_data *data, int y, int x)
{
	if (data->copy[y][x] != '1' && data->copy[y][x] != 'M'
		&& data->copy[y][x] != 'E')
	{
		if (data->copy[y][x] == 'C')
			data->copy_coin++;
		data->copy[y][x] = 'M';
		mark_again(data, y + 1, x);
		mark_again(data, y - 1, x);
		mark_again(data, y, x + 1);
		mark_again(data, y, x - 1);
	}
}
