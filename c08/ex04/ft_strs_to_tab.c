/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kelk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 09:41:53 by sel-kelk          #+#    #+#             */
/*   Updated: 2026/08/29 15:07:52 by sel-kelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char	*s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(ft_strlen(src) + 1);
	if (!str)
		return (0);
	while (src[i])
	{
		*(str + i) = src[i];
		i++;
	}
	*(str + i) = '\0';
	return (str);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*ar;
	int			i;

	ar = malloc((ac + 1) * (8 + 8 + 4 + 4));
	if (!ar)
		return (0);
	i = 0;
	while (i < ac)
	{
		ar[i].size = ft_strlen(av[i]);
		ar[i].str = av[i];
		ar[i].copy = ft_strdup(av[i]);
		i++;
	}
	ar[i].str = 0;
	return (ar);
}
