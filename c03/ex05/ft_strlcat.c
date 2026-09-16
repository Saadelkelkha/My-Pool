/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kelk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 10:07:39 by sel-kelk          #+#    #+#             */
/*   Updated: 2026/08/22 12:32:00 by sel-kelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	srclen;

	i = 0;
	while (dest[i])
		i++;
	srclen = 0;
	while (src[srclen] != '\0')
		srclen++;
	j = 0;
	if (i < size)
	{
		j = 0;
		while ((i + j + 1) < size && src[j] != '\0')
		{
			dest[i + j] = src[j];
			j++;
		}
		dest[i + j] = '\0';
		return (i + srclen);
	}
	else
		return (size + srclen);
}
