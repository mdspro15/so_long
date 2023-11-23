/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:51:35 by schiou            #+#    #+#             */
/*   Updated: 2023/05/25 14:17:48 by schiou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
int	main()
{
	char	*newline;
	int	fd;

	fd = open("abc.txt", O_RDONLY);

	newline = get_next_line(fd);
	while (newline != NULL)
	{
		printf("%s", newline);
		free(newline);
		newline = get_next_line(fd);
	}
	close(fd);
	return (0);
}
*/
char	*get_next_line(int fd)
{
	static char	*fullstr;
	char		*new;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	fullstr = ft_read_line(fd, fullstr);
	if (!fullstr)
		return (NULL);
	new = ft_extract_line(fullstr);
	fullstr = ft_get_rest(fullstr);
	return (new);
}

char	*ft_read_line(int fd, char *full)
{
	char	*buffer;
	ssize_t	size;

	size = 1;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (size > 0)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == -1)
		{
			free(buffer);
			free(full);
			return (NULL);
		}
		buffer[size] = '\0';
		full = ft_strjoin(full, buffer);
		if (ft_strchr(full, '\n'))
			break ;
	}
	free(buffer);
	return (full);
}

char	*ft_extract_line(char *full)
{
	int		i;
	char	*new;

	i = 0;
	if (!full[i])
		return (NULL);
	while (full[i] != '\n' && full[i])
		i++;
	new = malloc((i + 2) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (full[i] && full[i] != '\n')
	{
		new[i] = full[i];
		i++;
	}
	if (full[i] == '\n')
	{
		new[i] = full[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_get_rest(char *full)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	while (full[i] && full[i] != '\n')
		i++;
	if (!full[i])
	{
		free(full);
		return (NULL);
	}
	rest = malloc((ft_strlen(full) - i + 1) * sizeof(char));
	if (!rest)
		return (NULL);
	i++;
	j = 0;
	while (full[i])
		rest[j++] = full[i++];
	rest[j] = '\0';
	free(full);
	return (rest);
}
