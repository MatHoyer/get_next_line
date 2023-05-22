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

int	find_retour(char *str, int i)
{
	if (i == 0 && str[0] == '\n')
		return (0);
	while (i != 0)
	{
		i--;
		if (str[i] == '\n')
			return (i + 1);
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

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer_tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	val = read(fd, buffer_tmp, BUFFER_SIZE);
	buffer_tmp[val] = '\0';
	buffer = ft_strjoin(buffer, buffer_tmp, val);
	while (deb >= 0 && buffer[deb])
	{
		if (!valide(buffer, deb) && val > 0)
		{
			buffer_tmp = malloc(BUFFER_SIZE + 1);
			val = read(fd, buffer_tmp, BUFFER_SIZE);
			buffer_tmp[val] = 0;
			buffer = ft_strjoin(buffer, buffer_tmp, val);
		}
		if (buffer[deb] == '\n')
		{
			deb += 1;
			return (ft_strdup(buffer, find_retour(buffer, deb - 1), deb));
		}
		deb++;
	}
	if (val == 0 && deb > 0)
	{
		val = deb;
		deb = -1;
		if (val != find_retour(buffer, val))
			return (ft_strdup(buffer, find_retour(buffer, val), val));
		return (NULL);
	}
	return (NULL);
}


/*int main()
{
	int file = open("fichier.txt", O_RDONLY);
	char *str = get_next_line(file);
	printf("(1)%s", str);
	free(str);
	str = get_next_line(file);
	printf("(2)%s", str);
	free(str);
	str = get_next_line(file);
	printf("(3)%s", str);
	free(str);
	str = get_next_line(file);
	printf("(4)%s", str);
	free(str);
	str = get_next_line(file);
	printf("(5)%s", str);
	free(str);
	str = get_next_line(file);
	printf("(6)%s", str);
	free(str);
	str = get_next_line(file);
	printf("(7)%s", str);
	free(str);
	str = get_next_line(file);
	printf("(8)%s", str);
	free(str);
	str = get_next_line(file);
	printf("(9)%s", str);
	free(str);
	str = get_next_line(file);
	printf("(10)%s", str);
	free(str);
	

	close(file);
	return 0;
}*/
