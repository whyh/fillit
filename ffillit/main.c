/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 12:37:18 by dderevyn          #+#    #+#             */
/*   Updated: 2019/01/16 15:07:30 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	char	*all;
	char	**tets;
	int		fd;
	char	*map;
	size_t	y;

	if (argc != 2)
	{
		write(1, "usage: ./fillit source_file\n", 28);
		return (0);
	}
	all = ft_strnew(546);
	if ((fd = open(argv[1], O_RDONLY)) < 0 || read(fd, all, 546) <= 0
	|| !ft_valid_file(all) || !ft_valid_tets(all, &tets, NULL, -1))
	{
		write(1, "error\n", 6);
		return (0);
	}
	ft_strdel(&all);
	y = ft_base_map_size(tets);
	map = ft_new_map(y);
	while (ft_solve(tets, map) != 1)
		map = ft_new_map(++y);
	return (1);
}
