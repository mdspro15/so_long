/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 11:52:39 by schiou            #+#    #+#             */
/*   Updated: 2023/09/07 12:10:38 by schiou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void	handle_key(int keycode, t_data *data);
int		can_move(t_data *data, char next);
void	move(t_data *data, int cur_x, int cur_y);
int		close_window(t_data *data);

int	key_hook(int keycode, t_data *data)
{
	int	cur_y;
	int	cur_x;

	cur_y = data->player_y;
	cur_x = data->player_x;
	handle_key(keycode, data);
	if (can_move(data, data->map_data[data->player_y][data->player_x]))
	{
		if (data->map_data[data->player_y][data->player_x] == 'C')
		{
			data->num_coin--;
			move(data, cur_x, cur_y);
		}
		else
			move(data, cur_x, cur_y);
	}
	else
	{
		data->player_y = cur_y;
		data->player_x = cur_x;
	}
	return (0);
}

void	handle_key(int keycode, t_data *data)
{
	if (keycode == 53)
		close_window(data);
	if (keycode == 13)
		data->player_y -= 1;
	if (keycode == 1)
		data->player_y += 1;
	if (keycode == 0)
		data->player_x -= 1;
	if (keycode == 2)
		data->player_x += 1;
}

int	can_move(t_data *data, char next)
{
	if (next == '0' || next == 'C')
		return (1);
	if (next == 'E')
	{
		if (data->num_coin == 0)
		{
			printf("You win!");
			close_window(data);
		}
		return (0);
	}
	return (0);
}

void	move(t_data *data, int cur_x, int cur_y)
{
	data->map_data[data->player_y][data->player_x] = 'P';
	data->map_data[cur_y][cur_x] = '0';
	display_image(data);
	data->num_move++;
	write(1, "Your movement:", 14);
	ft_putnbr(data->num_move);
	write(1, "\n", 1);
}

int	close_window(t_data *data)
{
	free_map_data(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->tree);
	mlx_destroy_image(data->mlx, data->coin);
	mlx_destroy_image(data->mlx, data->exit);
	mlx_destroy_image(data->mlx, data->player);
	mlx_destroy_image(data->mlx, data->path);
	free(data->mlx);
	exit(0);
}
