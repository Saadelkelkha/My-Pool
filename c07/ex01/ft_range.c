/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kelk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 10:55:11 by sel-kelk          #+#    #+#             */
/*   Updated: 2026/08/29 15:50:43 by sel-kelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*n;
	int	i;

	if (min >= max)
		return (0);
	n = malloc((max - min) * 4);
	if (!n)
		return (0);
	i = 0;
	while (min + i < max)
	{
		*(n + i) = min + i;
		i++;
	}
	return (n);
}
