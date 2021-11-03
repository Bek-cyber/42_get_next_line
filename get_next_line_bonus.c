/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubolt <ubolt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 17:47:22 by ubolt             #+#    #+#             */
/*   Updated: 2020/12/19 17:48:38 by ubolt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	int			k;
	char		*buf;
	static char	*mas;

	if (fd < 0 || BUFFER_SIZE < 1 || !line || !(buf = malloc(BUFFER_SIZE + 1)))
		return (-1);
	k = 1;
	while (k > 0 && (ft_proverka_na_n(mas)) == -1)
	{
		k = read(fd, buf, BUFFER_SIZE);
		if (k == -1 || k == 0)
		{
			free(buf);
			*line = ft_zapis_stroki(mas);
			free(mas);
			mas = NULL;
			return (k);
		}
		buf[k] = '\0';
		mas = ft_strjoin(mas, buf);
	}
	free(buf);
	*line = ft_zapis_stroki(mas);
	mas = ft_smeshenie(mas);
	return (1);
}

int		ft_proverka_na_n(char *mas)
{
	int	i;

	if (!mas)
		return (-1);
	i = 0;
	while (mas[i])
	{
		if (mas[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		ft_razriv(char *mas)
{
	int		i;

	i = 0;
	while (mas[i] != '\0' && mas[i] != '\n')
		i++;
	return (i);
}

char	*ft_zapis_stroki(char *mas)
{
	char	*str;
	int		i;

	i = 0;
	if (!mas)
	{
		str = malloc(1);
		str[0] = '\0';
		return (str);
	}
	while (mas[i] && mas[i] != '\n')
		i++;
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (mas[i] && mas[i] != '\n')
	{
		str[i] = mas[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_smeshenie(char *mas)
{
	int		i;
	int		j;
	char	*str;

	i = ft_razriv(mas);
	if (mas[i] == '\0')
		return (NULL);
	i += 1;
	j = 0;
	while (mas[i + j])
		j++;
	str = malloc(j + 1);
	if (!str)
		return (NULL);
	j = 0;
	while (mas[i + j])
	{
		str[j] = mas[i + j];
		j++;
	}
	str[j] = '\0';
	free(mas);
	mas = NULL;
	return (str);
}
