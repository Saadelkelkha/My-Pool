/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kelk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 20:21:14 by sel-kelk          #+#    #+#             */
/*   Updated: 2026/08/17 16:18:59 by sel-kelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0 && str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 32;
		}
		else if (((str[i - 1] < 'A' && str[i - 1] > '9') || (str[i - 1] < '0')
				|| (str[i - 1] > 'Z' && str[i - 1] < 'a') || str[i - 1] > 'z' )
			&& str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 32;
		}
		else if (!((str[i - 1] < 'A' && str[i - 1] > '9') || (str[i - 1] < '0')
				|| (str[i - 1] > 'Z' && str[i - 1] < 'a') || str[i - 1] > 'z')
			&& str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}
