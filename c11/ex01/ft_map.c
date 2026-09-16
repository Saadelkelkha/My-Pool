/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kelk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 16:47:47 by sel-kelk          #+#    #+#             */
/*   Updated: 2026/09/01 17:00:02 by sel-kelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*newtab;
	int	i;

	newtab = malloc(length * sizeof(int));
	if (!newtab)
		return (0);
	i = 0;
	while (i < length)
	{
		newtab[i] = f(tab[i]);
		i++;
	}
	return (newtab);
}
