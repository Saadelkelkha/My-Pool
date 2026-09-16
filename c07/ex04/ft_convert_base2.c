/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kelk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 16:57:33 by sel-kelk          #+#    #+#             */
/*   Updated: 2026/08/25 17:59:27 by sel-kelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	is_negative(long *n, char *str, int *i)
{
	if (*n < 0)
	{
		*(str + (*i)) = '-';
		*n = -(*n);
		(*i)++;
	}
}

int	count_bytes(int nbr, int size)
{
	int		j;
	int		div;
	long	n;

	n = nbr;
	if (n < 0)
		n = -n;
	j = 0;
	div = 1;
	while (n / div >= size)
	{
		div = div * size;
		j++;
	}
	return (j + 3);
}

int	ft_sign(char *str, int *i)
{
	int	sign;

	sign = 1;
	while (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			sign = -sign;
		(*i)++;
	}
	return (sign);
}

int	get_nbr(char *str, int *i, char *base, int size)
{
	int	j;
	int	n;

	n = 0;
	while (str[*i])
	{
		j = 0;
		while (base[j] && str[*i] != base[j])
			j++;
		if (base[j])
			n = n * size + j;
		else
			break ;
		(*i)++;
	}
	return (n);
}

int	skip_whitespace(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == '\v')
		i++;
	return (i);
}
