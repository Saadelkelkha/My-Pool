/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kelk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 12:08:22 by sel-kelk          #+#    #+#             */
/*   Updated: 2026/08/31 16:42:15 by sel-kelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_get_size(int size, char **strs, char *sep)
{
	int	i;
	int	b;
	int	j;

	i = ft_strlen(sep);
	j = 0;
	b = 0;
	while (j < size)
	{
		if (j != size - 1)
			b = b + ft_strlen(strs[j]) + i;
		else
			b = b + ft_strlen(strs[j]);
		j++;
	}
	return (b);
}

void	set_str(char **strs, int i, int *y, char *c)
{
	int	j;

	j = 0;
	while (strs[i][j])
	{
		c[*y] = strs[i][j];
		(*y)++;
		j++;
	}
}

char	*ft_cat_strs(int size, char **strs, char *sep, char *c)
{
	int	j;
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (i < size)
	{
		j = 0;
		set_str(strs, i, &y, c);
		while (sep[j])
		{
			if (i != size - 1)
			{
				c[y] = sep[j];
				y++;
			}
			j++;
		}
		i++;
	}
	c[y] = '\0';
	return (c);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*c;

	if (size < 1)
	{
		c = malloc(1);
		if (!c)
			return (0);
		*c = '\0';
		return (c);
	}
	c = malloc(ft_get_size(size, strs, sep) + 1);
	if (!c)
		return (0);
	return (ft_cat_strs(size, strs, sep, c));
}
