/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kelk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 19:05:21 by sel-kelk          #+#    #+#             */
/*   Updated: 2026/08/22 18:46:50 by sel-kelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_baselen_invalid_base(char *base, int	*size_of_base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	while (base[*size_of_base])
	{
		if (base[*size_of_base] == '+' || base[*size_of_base] == '-')
			return (1);
		(*size_of_base)++;
	}
	return (0);
}

int	skip_whitespace(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == '\v')
	{
		i++;
	}
	return (i);
}

int	ft_sign(char *str, int *i)
{
	int	sign;

	sign = 1;
	while (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
		{
			sign = sign * -1;
		}
		(*i)++;
	}
	return (sign);
}

int	nbr(char *str, int *i, char *base, int size)
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

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	n;
	int	size_of_base;

	size_of_base = 0;
	if (ft_baselen_invalid_base(base, &size_of_base) || size_of_base < 2)
		return (0);
	i = skip_whitespace(str);
	sign = ft_sign(str, &i);
	n = nbr(str, &i, base, size_of_base) * sign;
	return (n);
}
