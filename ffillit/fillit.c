/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 16:19:59 by dderevyn          #+#    #+#             */
/*   Updated: 2019/01/13 16:20:02 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_new_map(size_t y)
{
	char	*str;
	int		i;
	size_t	x;

	i = -1;
	x = y + 1;
	str = ft_strnew(x * y);
	while (++i < (int)(x * y))
	{
		if (i != 0 && (i + 1) % x == 0)
			str[i] = '\n';
		else
			str[i] = '.';
	}
	return (str);
}

int		ft_solve(char **tets, char *map)
{
	int		w;
	size_t	size;
	char	**dmaps;

	dmaps = (char **)malloc(sizeof(char *) * (1 + 26));
	w = 27;
	while (w-- > 0)
		dmaps[w] = NULL;
	size = ft_linelen(map);
	while (tets[++w])
	{
		dmaps[w] = ft_strdup(map);
		while (!ft_fill_map(tets[w], &map, size, 0))
			if (!ft_solve2(&map, &w, &dmaps))
				return (0);
		ft_clean_map(&map);
	}
	ft_putstr(map);
	ft_strdel(&map);
	w = 0;
	while (w++ < 26)
		if (dmaps[w - 1] != NULL)
			ft_strdel(&(dmaps[w - 1]));
	free(dmaps);
	return (1);
}

int		ft_fill_map(char *t, char **p, size_t s, size_t i)
{
	size_t	m;
	size_t	ts;

	m = 0;
	ts = ft_linelen(t);
	while (t[i] != '\0' && (*p)[m] != '\0')
	{
		if (!ft_fill_map2(t, p, &i, &m))
			break ;
		if ((t[i] >= 'A' && t[i] <= 'Z') && (*p)[m] == '.' && !(t[i - 1] == t[i]
		&& t[i] != (*p)[m - 1]) && !(t[i - ts - 1] == t[i] && (*p)[m - s - 1] !=
		t[i]) && !(t[i - ts - 1] == '.' && (*p)[m - s - 1] == t[i]) && !(i >= ts
		* 2 + 2 && m >= s * 2 + 2 && t[i - ts - 1] == t[i] && t[i - ts * 2 - 2]
		== t[i] && (*p)[m - s * 2 - 2] != t[i]) && !(t[0] == '.' && t[1] == '.'
		&& i == ts + 1 && t[i - ts + 1] == t[i] && t[i] != (*p)[m - s + 1]) &&
		!(t[i] == t[i + 1] && t[i] == t[i - ts] && (*p)[m - s] != t[i]))
			(*p)[m] = t[i++];
		++m;
	}
	if (t[i] != '\0' && t[i + 1] != '\0')
		return (0);
	return (1);
}

int		ft_put_one(char **map)
{
	int i;

	i = 0;
	while ((*map)[i] != '\0')
	{
		if ((*map)[i] == '.')
		{
			(*map)[i] = '1';
			return (1);
		}
		++i;
	}
	return (0);
}

void	ft_clean_map(char **map)
{
	int i;

	i = 0;
	while ((*map)[i])
	{
		if ((*map)[i] == '1')
			(*map)[i] = '.';
		++i;
	}
}
