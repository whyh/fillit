/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 12:37:27 by dderevyn          #+#    #+#             */
/*   Updated: 2019/01/10 12:37:32 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_valid_file(char *all)
{
	int i;
	int	n;
	int	k;

	i = 0;
	k = -42;
	while (all[i] != '\0')
	{
		if (k != -42)
			if (all[i++] != '\n')
				return (0);
		k = 4;
		while (k-- > 0)
		{
			n = 4;
			while (n-- > 0)
				if ((++i) && all[i - 1] != '#' && all[i - 1] != '.')
					return (0);
			if (all[i] != '\n' || i > 546)
				return (0);
			if (all[i] == '\n')
				++i;
		}
	}
	return (1);
}

char	**split_tets(char *all, int c, size_t i, size_t w)
{
	char	**tts;

	i = ft_strlen(all);
	w = 1 + (i / 21);
	tts = (char **)malloc(sizeof(char *) * (1 + w));
	i = 0;
	while (i < w && (tts[i] = (char *)malloc(sizeof(char) * 22)))
	{
		ft_memset(tts[i], '\0', 22);
		++i;
	}
	tts[i] = NULL;
	w = 0;
	c = 0;
	i = 0;
	while (all[i])
	{
		if (all[i] != '\n' || all[i - 1] != '\n')
			tts[w][c++] = all[i];
		else if (all[i] == '\n' && all[i - 1] == '\n' && !(c = 0))
			++w;
		++i;
	}
	return (tts);
}

void	ft_paint_tets(char **tets)
{
	int i;
	int w;

	w = 0;
	while (tets[w])
	{
		i = 0;
		while (tets[w][i])
		{
			if (tets[w][i] == '#')
				tets[w][i] = (char)(w + 65);
			++i;
		}
		++w;
	}
}

int		ft_valid_tets(char *all, char ***tets, char **t, int r)
{
	*tets = split_tets(all, 0, 0, 0);
	t = *tets;
	while (t[++r] != NULL)
	{
		t[r] = ft_cut_y(t[r]);
		t[r] = ft_cut_y1(t[r]);
		t[r] = ft_cut_x(t[r]);
		t[r] = ft_cut_x1(t[r]);
	}
	r = -1;
	while (t[++r])
		if (!ft_strequ(t[r], "####\n") && !ft_strequ(t[r], "#\n#\n#\n#\n")
		&& !ft_strequ(t[r], "###\n#..\n") && !ft_strequ(t[r], "##\n##\n")
		&& !ft_strequ(t[r], "###\n.#.\n") && !ft_strequ(t[r], "###\n..#\n")
		&& !ft_strequ(t[r], "##\n.#\n.#\n") && !ft_strequ(t[r], ".#\n##\n.#\n")
		&& !ft_strequ(t[r], ".#\n##\n.#\n") && !ft_strequ(t[r], ".#\n.#\n##\n")
		&& !ft_strequ(t[r], "#..\n###\n") && !ft_strequ(t[r], ".#.\n###\n")
		&& !ft_strequ(t[r], "..#\n###\n") && !ft_strequ(t[r], "#.\n#.\n##\n")
		&& !ft_strequ(t[r], "#.\n##\n#.\n") && !ft_strequ(t[r], "##\n#.\n#.\n")
		&& !ft_strequ(t[r], "##.\n.##\n") && !ft_strequ(t[r], ".#\n##\n#.\n")
		&& !ft_strequ(t[r], ".##\n##.\n") && !ft_strequ(t[r], "#.\n##\n.#\n"))
			return (0);
	ft_paint_tets(*tets);
	return (1);
}
