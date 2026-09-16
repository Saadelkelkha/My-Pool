/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kelk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 13:26:00 by sel-kelk          #+#    #+#             */
/*   Updated: 2026/08/25 18:01:35 by sel-kelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	is_negative(long *n, char *str, int *i);
int		count_bytes(int nbr, int size);
int		ft_sign(char *str, int *i);
int		get_nbr(char *str, int *i, char *base, int size);
int		skip_whitespace(char *str);

int	ft_strlen(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j] && base[i] != base[j])
			j++;
		if (base[j] || base[i] == '+' || base[i] == '-')
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	n;
	int	size;

	size = ft_strlen(base);
	i = skip_whitespace(str);
	sign = ft_sign(str, &i);
	n = get_nbr(str, &i, base, size);
	return (n * sign);
}

char	*putnbr(int nbr, char *base)
{
	long	n;
	int		size;
	int		div;
	char	*str;
	int		i;

	size = ft_strlen(base);
	str = malloc(count_bytes(nbr, size));
	n = nbr;
	i = 0;
	is_negative(&n, str, &i);
	div = 1;
	while (n / div >= size)
		div = div * size;
	while (div > 0)
	{
		*(str + i) = base[((n / div) % size)];
		div = div / size;
		i++;
	}
	*(str + i) = '\0';
	return (str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	if (check_base(base_from) || ft_strlen(base_from) < 2
		|| check_base(base_to) || ft_strlen(base_to) < 2)
		return (0);
	return (putnbr(ft_atoi_base(nbr, base_from), base_to));
}
