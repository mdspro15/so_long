/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:41:26 by schiou            #+#    #+#             */
/*   Updated: 2023/09/06 13:36:50 by schiou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void	get_map_height(t_data *data, char *file);
void	store_map_data(t_data *data, char *file);

void	read_map(t_data *data, char *file)
{
	get_map_height(data, file);
	store_map_data(data, file);
}

//get map height so that we can allocate memory for 2D array
void	get_map_height(t_data *data, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error");
		exit(1);
	}
	while (1)
	{
		line = get_next_line(fd);
		data->height++;
		if (line == NULL)
			break ;
		free(line);
	}
	data->height--;
	close(fd);
}

//Store each line of map file to 2D array
void	store_map_data(t_data *data, char *file)
{
	int	i;
	int	fd;

	i = 0;
	data->map_data = (char **)malloc(sizeof(char *) * (data->height + 1));
	if (data->map_data == NULL)
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
		data->map_data[i] = get_next_line(fd);
		i++;
	}
	data->map_data[i] = NULL;
	close(fd);
}
