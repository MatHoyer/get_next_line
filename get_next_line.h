/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:22:33 by mhoyer            #+#    #+#             */
/*   Updated: 2023/05/15 12:22:34 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h> 
# include <fcntl.h>
# include <unistd.h>

char	*get_next_line(int fd);

char	*ft_strdup(char *s, int deb, int end);

int		ft_strlen(const char *s);

char	*ft_strjoin(char *s1, char *s2, int t_s2);

#endif