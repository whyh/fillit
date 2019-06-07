/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 16:45:35 by dderevyn          #+#    #+#             */
/*   Updated: 2019/01/13 16:45:39 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t	ft_base_map_size(char **tets)
{
	int	y;
	int w;
	int i;
	int n;

	w = 0;
	y = 2;
	n = 0;
	while (tets[w])
	{
		i = 0;
		while (tets[w][i])
		{
			if ((tets[w][i] >= 'A' && tets[w][i] <= 'Z'))
			{
				++n;
				if (y * y < n)
					++y;
			}
			++i;
		}
		++w;
	}
	return ((size_t)y);
}

int		ft_fill_map2(char *t, char **p, size_t *i, size_t *m)
{
	int		d;
	size_t	s;
	size_t	ts;

	s = ft_linelen(*p);
	ts = ft_linelen(t);
	if (t[(*i)] == '\n' && ((*i) = (*i) + 1))
		while ((*p)[(*m)] != '\n')
			++(*m);
	d = 0;
	while (t[(*i) + d] == '.' && (d = d + 1))
		while ((*i) > ts && (*p)[(*m)] != '\0'
			&& (*p)[(*m) - s - 1] != t[(*i) - ts - 1]
			&& t[(*i) - ts - 1] >= 'A' && t[(*i) - ts - 1] <= 'Z')
			++(*m);
	if ((*p)[(*m)] == '\0')
		return (0);
	(*i) += d;
	while (d-- && (*p)[(*m) + 1] != '\n' && (*p)[(*m)] != '\n')
		++(*m);
	return (1);
}

int		ft_solve2(char **map, int *w, char ***dmaps)
{
	char	**p;

	p = *dmaps;
	ft_strdel(map);
	*map = ft_strdup(p[(*w)]);
	if (!ft_put_one(map))
	{
		if ((*w) == 0)
		{
			ft_strdel(map);
			ft_strdel(&(p[(*w)]));
			free(*dmaps);
			return (0);
		}
		ft_strdel(map);
		ft_strdel(&(p[(*w)]));
		(*w)--;
		*map = ft_strdup(p[(*w)]);
		ft_put_one(map);
	}
	ft_strdel(&(p[(*w)]));
	p[(*w)] = ft_strdup(*map);
	return (1);
}
