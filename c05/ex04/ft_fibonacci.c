/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kelk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 09:49:34 by sel-kelk          #+#    #+#             */
/*   Updated: 2026/08/23 10:30:38 by sel-kelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	int	n;

	if (index < 0)
		return (-1);
	if (index < 1)
		return (0);
	if (index < 2)
		return (1);
	n = ft_fibonacci(index - 2) + ft_fibonacci(index - 1);
	return (n);
}
