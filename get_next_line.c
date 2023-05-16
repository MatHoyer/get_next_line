/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:22:40 by mhoyer            #+#    #+#             */
/*   Updated: 2023/05/15 12:22:42 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

int	valide(char *str, int start)
{
	int	i;

	i = start;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

#include <stdio.h>
char	*get_next_line(int fd)
{
	static char			*buffer = NULL;
	char				*buffer_tmp;
	static int			deb = 0;
	int					val;

	buffer_tmp = malloc(BUFFER_SIZE + 1);
	val = read(fd, buffer_tmp, BUFFER_SIZE);
	buffer_tmp[val] = 0;
	if (!buffer)
		buffer = ft_strdup(buffer_tmp, 0, val);
	else
		buffer = ft_strjoin(buffer, buffer_tmp);
	while (buffer[deb])
	{
		if (!valide(buffer, deb) && val == BUFFER_SIZE)
		{
			buffer_tmp = malloc(BUFFER_SIZE + 1);
			val = read(fd, buffer_tmp, BUFFER_SIZE);
			buffer_tmp[val] = 0;
			buffer = ft_strjoin(buffer, buffer_tmp);
		}
		if (buffer[deb] == '\n')
		{
			deb += 1;
			return (ft_strdup(buffer, find_retour(buffer, deb - 2), deb));
		}
		deb++;
	}
	if (val < BUFFER_SIZE && val != 0)
	{
		val = 0;
		return (ft_strdup(buffer, find_retour(buffer, (deb + val) - 2), (deb + val)));
	}
	return (NULL);
}


int main()
{
	int file = open("fichier.txt", O_RDONLY);
	char *str = get_next_line(file);
	printf("%s", str);
	free(str);
	str = get_next_line(file);
	printf("%s", str);
	free(str);
	str = get_next_line(file);
	printf("%s", str);
	free(str);
	str = get_next_line(file);
	printf("%s", str);
	free(str);
	str = get_next_line(file);
	printf("%s", str);
	free(str);
	str = get_next_line(file);
	printf("%s", str);
	free(str);
	str = get_next_line(file);
	printf("%s", str);
	free(str);
	str = get_next_line(file);
	printf("%s", str);
	free(str);
	

	close(file);
	return 0;
}
