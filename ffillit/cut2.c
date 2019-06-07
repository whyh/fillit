/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 16:18:23 by dderevyn          #+#    #+#             */
/*   Updated: 2019/01/13 16:18:27 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_uptetx(char *uptet)
{
	int			i;
	static int	c;
	int			h;
	int			x;

	i = -1;
	c = 0;
	x = 0;
	h = 0;
	while (uptet[++i] != '\0')
	{
		x++;
		if (uptet[i] == '#' && uptet[i - 1] != '#')
		{
			if ((h >= x) || c == 0)
			{
				h = x;
				c = h;
			}
		}
		if (uptet[i] == '\n')
			x = 0;
	}
	return (c - 1);
}

int		ft_uptetx1(char *uptet)
{
	int			i;
	static int	c;
	int			h;
	int			x1;
	int			l;

	i = -1;
	c = 0;
	x1 = 0;
	h = 0;
	while (uptet[++i] != '\0')
	{
		if (uptet[i] == '#' && uptet[i + 1] != '#')
		{
			l = i;
			while (uptet[l++] != '\n')
				x1++;
			if (((h >= x1) || c == 0) && (h = x1))
				c = h;
			x1 = 0;
		}
	}
	return (c - 1);
}

int		ft_uptety(char *uptet)
{
	int			i;
	static int	c;
	int			y;

	i = -1;
	c = 0;
	y = 0;
	while (uptet[++i] != '\0')
	{
		if (uptet[i] == '\n')
			y++;
		if (uptet[i] == '#')
		{
			c = y;
			return (c);
		}
	}
	return (-1);
}

int		ft_uptety1(char *uptet)
{
	size_t		i;
	static int	c;
	int			y;

	c = 0;
	y = -1;
	i = ft_strlen(uptet);
	while (--i > 0)
	{
		if (uptet[i] == '\n')
			y++;
		if (uptet[i] == '#')
		{
			c = y;
			return (c);
		}
	}
	return (-1);
}

char	*ft_cut_y(char *str)
{
	int		i;
	char	*cut;
	int		j;
	int		c;

	i = -1;
	j = -1;
	c = ft_uptety(str);
	if (!(cut = (char *)malloc((ft_strlen(str) - c * 5 + 1) * sizeof(char))))
		return (NULL);
	while (str[++j])
	{
		while (c > 0)
		{
			j = j + 5;
			c--;
		}
		cut[++i] = str[j];
	}
	cut[++i] = '\0';
	ft_strdel(&str);
	return (cut);
}
