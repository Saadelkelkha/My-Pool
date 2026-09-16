/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kelk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 18:11:28 by sel-kelk          #+#    #+#             */
/*   Updated: 2026/09/02 08:39:39 by sel-kelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_is_sort(int *tab, int length, int (*f)(int, int), int sort)
{
	int	i;

	i = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) < 0 && sort <= 0)
			return (0);
		else if (f(tab[i], tab[i + 1]) > 0 && sort >= 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	sort;

	i = 0;
	sort = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) < 0)
		{
			sort = 1;
			break ;
		}
		else if (f(tab[i], tab[i + 1]) > 0)
		{
			sort = -1;
			break ;
		}
		i++;
	}
	return (ft_check_is_sort(tab, length, f, sort));
}
