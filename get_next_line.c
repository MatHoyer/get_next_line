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

#include <stdio.h>

char	*get_next_line(int fd)
{
	static char			*buffer;
	char				*buffer_tmp;
	static int			deb = 0;

	buffer = malloc(BUFFER_SIZE + 1);
	read(fd, buffer, BUFFER_SIZE);
	while (buffer[deb])
	{
		if (!buffer[deb + 1])
		{
			buffer_tmp = malloc(BUFFER_SIZE + 1);
			read(fd, buffer_tmp, BUFFER_SIZE);
			buffer = ft_strjoin(buffer, buffer_tmp);
		}
		if (buffer[deb] == '\n')
		{
			deb += 1;
			return (ft_strdup(buffer, find_retour(buffer, deb - 2), deb - 1));
		}
		deb++;
	}
	return (NULL);
}

int main()
{
	int file = open("fichier.txt", O_RDONLY);
	
	printf("%s", get_next_line(file));
	close(file);
	file = open("fichier.txt", O_RDONLY);
	printf("%s", get_next_line(file));
	close(file);
	file = open("fichier.txt", O_RDONLY);
	printf("%s", get_next_line(file));
	close(file);
	file = open("fichier.txt", O_RDONLY);
	printf("%s", get_next_line(file));
close(file);
	file = open("fichier.txt", O_RDONLY);
	printf("%s", get_next_line(file));
	close(file);
	file = open("fichier.txt", O_RDONLY);
	printf("%s", get_next_line(file));
	close(file);
	return 0;
}