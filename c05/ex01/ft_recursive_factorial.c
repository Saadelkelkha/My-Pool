/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kelk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 09:00:24 by sel-kelk          #+#    #+#             */
/*   Updated: 2026/08/23 14:35:55 by sel-kelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int	n;

	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	n = nb;
	if (nb > 1)
	{
		n = n * ft_recursive_factorial(nb - 1);
	}
	return (n);
}
