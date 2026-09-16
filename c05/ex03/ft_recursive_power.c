/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kelk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 09:38:50 by sel-kelk          #+#    #+#             */
/*   Updated: 2026/08/23 14:23:34 by sel-kelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	n;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	n = nb;
	if (power > 1)
	{
		n = n * ft_recursive_power(nb, power - 1);
	}
	return (n);
}
