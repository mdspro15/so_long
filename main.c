/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:08:19 by schiou            #+#    #+#             */
/*   Updated: 2023/09/06 14:34:44 by schiou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void	initialize_structure(t_data *data);
void	initialize_mlx(t_data *data);

int	main(int ac, char **argv)
{
	t_data	data;

	check_arg(ac, argv[1]);
	initialize_structure(&data);
	read_map(&data, argv[1]);
	check_map(&data);
	is_valid_path(&data, argv[1]);
	initialize_mlx(&data);
	display_image(&data);
	mlx_hook(data.win, 2, 0, key_hook, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
	return (0);
}

void	initialize_structure(t_data *data)
{
	data->height = 0;
	data->width = 0;
	data->num_player = 0;
	data->num_exit = 0;
	data->num_coin = 0;
	data->player_x = 0;
	data->player_y = 0;
	data->num_move = 0;
	data->copy_coin = 0;
	data->copy_exit = 0;
}

void	initialize_mlx(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window
		(data->mlx, data->width * 50, data->height * 50, "so_long");
	if (data->mlx == NULL || data->win == NULL)
		free_map_data_with_error(data, "Mlx is NULL");
}
