/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kelk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 09:29:10 by sel-kelk          #+#    #+#             */
/*   Updated: 2026/09/02 09:49:02 by sel-kelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	long	n;
	char	*s;

	n = nb;
	s = "0123456789";
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		n = n % 10;
	}
	write(1, &s[n], 1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	n;

	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == '\v')
		i++;
	sign = 1;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	n = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		n = (n * 10) + (str[i] - '0');
		i++;
	}
	n = n * sign;
	return (n);
}

int	do_op(char **argv)
{
	int	n;

	n = 0;
	if (argv[2][0] == '+')
		n = ft_atoi(argv[1]) + ft_atoi(argv[3]);
	if (argv[2][0] == '-')
		n = ft_atoi(argv[1]) - ft_atoi(argv[3]);
	if (argv[2][0] == '*')
		n = ft_atoi(argv[1]) * ft_atoi(argv[3]);
	if (argv[2][0] == '/')
	{
		if (ft_atoi(argv[3]) == 0)
			write(2, "Stop : division by zero", 23);
		else
			n = ft_atoi(argv[1]) / ft_atoi(argv[3]);
	}
	if (argv[2][0] == '%')
	{
		if (ft_atoi(argv[3]) == 0)
			write(2, "Stop : modulo by zero", 21);
		else
			n = ft_atoi(argv[1]) % ft_atoi(argv[3]);
	}
	return (n);
}

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		if ((argv[2][0] == '%' || argv[2][0] == '/') && ft_atoi(argv[3]) == 0)
			do_op(argv);
		else
			ft_putnbr(do_op(argv));
		write(1, "\n", 1);
	}
	return (0);
}
