/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:22:51 by mhoyer            #+#    #+#             */
/*   Updated: 2023/05/15 12:22:53 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*conc;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	conc = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (conc == NULL)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		conc[i] = s1[i];
		i++;
	}
	while (i < ft_strlen(s1) + ft_strlen(s2))
	{
		conc[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	conc[i] = '\0';
	free(s1);
	free(s2);
	return (conc);
}

void	*ft_memcpy(void *dest, const void *src, int deb, int end)
{
	const char	*s;
	char		*d;
	int			i;

	if (!dest)
		return (NULL);
	s = src;
	d = dest;
	i = 0;
	while (deb < end)
	{
		d[i] = s[deb];
		deb++;
		i++;
	}
	return (dest);
}

char	*ft_strdup(const char *s, int deb, int end)
{
	char	*str;

	str = malloc((end - deb) + 1);
	if (!str)
		return (NULL);
	if (ft_memcpy(str, s, deb, end) == NULL)
		return (NULL);
	str[end - deb] = '\0';
	return (str);
}

int	find_retour(char *str, int i)
{
	while (i != 0 && str[i] != '\n')
	{
		i--;
	}
	return (i);
}
