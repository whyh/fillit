/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 16:18:51 by dderevyn          #+#    #+#             */
/*   Updated: 2019/01/13 16:18:53 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_cut_y1(char *str)
{
	size_t	i;
	size_t	j;
	int		c;
	char	*cut;

	i = 0;
	j = 0;
	c = ft_uptety1(str);
	if (!(cut = (char *)malloc((ft_strlen(str) - c * 5 + 1) * sizeof(char))))
		return (NULL);
	while (j != ft_strlen(str) - c * 5)
	{
		cut[i] = str[j];
		++i;
		++j;
	}
	cut[i] = '\0';
	ft_strdel(&str);
	return (cut);
}

int		ft_n(char *str)
{
	int	i;
	int	a;

	i = -1;
	a = 0;
	while (str[++i])
	{
		if (str[i] == '\n')
			++a;
	}
	return (a);
}

char	*ft_cut_x(char *str)
{
	int		i;
	char	*cut;
	int		j;
	int		l;

	i = -1;
	j = -1;
	l = 0;
	if (!(cut = (char *)malloc((ft_strlen(str) -
			ft_uptetx(str) * ft_n(str) + 1) * sizeof(char))))
		return (NULL);
	while (str[++j])
	{
		l++;
		if (l > ft_uptetx(str) || l % 5 == 0)
			cut[++i] = str[j];
		if (l % 5 == 0)
			l = 0;
	}
	cut[++i] = '\0';
	ft_strdel(&str);
	return (cut);
}

char	*ft_cut_x1(char *str)
{
	int		i;
	char	*cut;
	int		j;
	size_t	k;
	int		c;

	k = ft_strlen(str) - ft_uptetx1(str) * ((ft_n(str) + 1));
	i = -1;
	j = -1;
	cut = ft_strnew(k);
	c = ft_uptetx1(str);
	while (str[++j])
	{
		if ((str[j + c] != '\n' || str[j] == '\n' || str[j] == '\0'))
			cut[++i] = str[j];
		else
			--c;
		if (str[j] == '\n' || str[j] == '\0')
			c = ft_uptetx1(str);
	}
	cut[++i] = '\0';
	ft_strdel(&str);
	return (cut);
}
