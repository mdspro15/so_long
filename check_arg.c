/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 09:14:09 by schiou            #+#    #+#             */
/*   Updated: 2023/09/01 12:04:40 by schiou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n);

void	check_arg(int ac, char *argv)
{
	char	*extention;

	extention = ft_strchr(argv, '.');
	if (extention)
	{
		if (ft_strncmp(extention, ".ber", 4) != 0)
		{
			write(1, "Wrong file extention", 20);
			exit(1);
		}
	}
	if (ac < 2)
	{
		write(1, "Please pass mapfile", 19);
		exit(1);
	}
	else if (ac > 2)
	{
		write(1, "Too many arguments", 18);
		exit(1);
	}
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
