/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:22:04 by schiou            #+#    #+#             */
/*   Updated: 2023/09/05 13:52:34 by schiou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void	free_map_data(t_data *data)
{
	int	y;

	y = 0;
	while (y < data->height)
	{
		free(data->map_data[y]);
		y++;
	}
	free(data->map_data);
	data->map_data = NULL;
}

void	free_map_data_with_error(t_data *data, char *msg)
{
	int	i;

	i = 0;
	free_map_data(data);
	while (msg[i])
	{
		write(1, &msg[i], 1);
		i++;
	}
	exit(1);
}

void	free_copy_map(t_data *data)
{
	int	y;

	y = 0;
	while (data->copy[y])
	{
		free(data->copy[y]);
		y++;
	}
	free(data->copy);
	data->copy = NULL;
}

void	ft_putnbr(int n)
{
	char	digit;

	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		digit = n + 48;
		write(1, &digit, 1);
	}
}
