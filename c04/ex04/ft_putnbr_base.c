/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kelk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 17:00:31 by sel-kelk          #+#    #+#             */
/*   Updated: 2026/08/22 15:24:49 by sel-kelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_duplicate_char(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j] && base[i] != base[j])
			j++;
		if (base[j])
			return (1);
		i++;
	}
	return (0);
}

int	ft_baselen_invalid_base(char *base, int	*size_of_base)
{
	while (base[*size_of_base])
	{
		if (base[*size_of_base] == '+' || base[*size_of_base] == '-')
			return (1);
		(*size_of_base)++;
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	n;
	int		size_of_base;

	size_of_base = 0;
	if (ft_baselen_invalid_base(base, &size_of_base)
		|| size_of_base < 2 || ft_duplicate_char(base))
		return ;
	n = nbr;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= size_of_base)
	{
		ft_putnbr_base(n / size_of_base, base);
		n = n % size_of_base;
	}
	write(1, &base[n], 1);
}
