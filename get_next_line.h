/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubolt <ubolt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 14:58:31 by ubolt             #+#    #+#             */
/*   Updated: 2020/12/19 17:33:28 by ubolt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 25
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int		ft_strlen(char *s1);
int		ft_proverka_na_n(char *mas);
int		ft_razriv(char *mas);
char	*ft_strjoin(char *mas, char *buf);
char	*ft_zapis_stroki(char	*mas);
char	*ft_smeshenie(char *mas);
int		ft_free(char *mas);
int		get_next_line(int fd, char **line);

#endif
