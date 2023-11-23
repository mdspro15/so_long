/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:22:09 by schiou            #+#    #+#             */
/*   Updated: 2023/09/06 14:12:25 by schiou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_data
{
	int		height;
	int		width;
	int		num_player;
	int		num_exit;
	int		num_coin;
	int		player_x;
	int		player_y;
	int		num_move;
	char	**map_data;
	char	*tree;
	char	*coin;
	char	*path;
	char	*exit;
	char	*player;
	void	*mlx;
	void	*win;
	char	**copy;
	int		copy_coin;
	int		copy_exit;
}	t_data;

void	free_map_data(t_data *data);
void	free_map_data_with_error(t_data *data, char *msg);
void	free_copy_map(t_data *data);
void	ft_putnbr(int n);
void	check_arg(int ac, char *argv);
void	read_map(t_data *data, char *file);
void	check_map(t_data *data);
void	is_valid_path(t_data *data, char *file);
void	display_image(t_data *data);
int		key_hook(int keycode, t_data *data);
int		close_window(t_data *data);

#endif
