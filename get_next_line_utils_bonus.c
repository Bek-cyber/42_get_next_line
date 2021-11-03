/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubolt <ubolt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 17:47:31 by ubolt             #+#    #+#             */
/*   Updated: 2020/12/19 17:49:00 by ubolt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *s1)
{
	int	i;

	if (!s1)
		return (0);
	i = 0;
	while (s1[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *mas, char *buf)
{
	char	*str;
	int		i;
	int		j;

	if (!mas && !buf)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(mas) + ft_strlen(buf) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (mas && mas[i])
	{
		str[i] = mas[i];
		i++;
	}
	if (mas)
		free(mas);
	while (buf && buf[j])
	{
		str[i + j] = buf[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

int		ft_free(char *mas)
{
	if (mas)
	{
		free(mas);
		mas = NULL;
	}
	return (-1);
}
