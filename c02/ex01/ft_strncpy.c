/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kelk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 15:18:59 by sel-kelk          #+#    #+#             */
/*   Updated: 2026/08/18 18:59:12 by sel-kelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	oversize;
	unsigned int	i;

	oversize = 0;
	i = 0;
	while (i < n)
	{
		if (oversize)
		{
			dest[i] = '\0';
		}
		else
		{
			dest[i] = src[i];
			if (!(src[i]))
			{
				oversize = 1;
			}
		}
		i++;
	}
	return (dest);
}
