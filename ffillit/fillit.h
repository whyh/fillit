/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 16:42:04 by dderevyn          #+#    #+#             */
/*   Updated: 2019/01/13 16:42:06 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

char	*ft_cut_y1(char *str);
int		ft_n(char *str);
char	*ft_cut_x(char *str);
char	*ft_cut_x1(char *str);
int		ft_uptetx(char *uptet);
int		ft_uptetx1(char *uptet);
int		ft_uptety(char *uptet);
int		ft_uptety1(char *uptet);
char	*ft_cut_y(char *str);
char	*ft_new_map(size_t y);
int		ft_solve(char **tets, char *map);
int		ft_fill_map(char *t, char **p, size_t s, size_t i);
int		ft_put_one(char **map);
void	ft_clean_map(char **map);
int		ft_valid_file(char *all);
char	**split_tets(char *all, int c, size_t i, size_t w);
void	ft_paint_tets(char **tets);
int		ft_valid_tets(char *all, char ***tets, char **tts, int r);
size_t	ft_base_map_size(char **tets);
int		ft_fill_map2(char *t, char **p, size_t *i, size_t *m);
int		ft_solve2(char **map, int *w, char ***dmaps);

#endif
