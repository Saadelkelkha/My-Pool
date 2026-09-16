/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kelk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 16:08:33 by sel-kelk          #+#    #+#             */
/*   Updated: 2026/08/25 09:58:05 by sel-kelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_params(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	ft_switch_params(char **argv, int i, int j)
{
	char	*c;
	int		y;

	y = 0;
	while (argv[i][y] && argv[j][y])
	{
		if (argv[i][y] > argv[j][y])
		{
			c = argv[j];
			argv[j] = argv[i];
			argv[i] = c;
			break ;
		}
		else if (argv[i][y] < argv[j][y])
			break ;
		y++;
	}
	if (argv[j][y] == '\0' && argv[i][y])
	{
		c = argv[j];
		argv[j] = argv[i];
		argv[i] = c;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			ft_switch_params(argv, i, j);
			j++;
		}
		i++;
	}
	ft_print_params(argc, argv);
	return (0);
}
