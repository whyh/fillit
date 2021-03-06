/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 14:33:00 by dderevyn          #+#    #+#             */
/*   Updated: 2018/11/16 14:42:39 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	static_ft_size(int size, int nb, int base)
{
	if (nb < 0)
	{
		nb = -nb;
		++size;
	}
	while (nb / base > 0)
	{
		nb = nb / base;
		++size;
	}
	return (size);
}

static int	static_ft_fdset(char *set)
{
	int	i;
	int	i2;

	i = 0;
	while (set[i])
	{
		if (!ft_isalnum((int)set[i]))
			return (1);
		++i;
	}
	i = 0;
	while (set[i])
	{
		i2 = i + 1;
		while (set[i2])
		{
			if (set[i] == set[i2])
				return (1);
			++i2;
		}
		++i;
	}
	if (i < 2)
		return (1);
	return (0);
}

char		*ft_itoabase(char *set, int nb)
{
	char	*str;
	int		base;
	int		size;

	if (!set || static_ft_fdset(set))
		return (NULL);
	base = ft_strlen(set);
	size = static_ft_size(1, nb, base);
	if (!(str = ft_strnew(size)))
		return (NULL);
	if (nb < 0)
	{
		nb = -nb;
		str[0] = '-';
	}
	while (nb != 0)
	{
		--size;
		str[size] = set[nb % base];
		nb = nb / base;
	}
	return (str);
}
