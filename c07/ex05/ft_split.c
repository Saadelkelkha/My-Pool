/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kelk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 18:04:02 by sel-kelk          #+#    #+#             */
/*   Updated: 2026/08/31 08:55:16 by sel-kelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(int f, int t, char *str)
{
	char	*c;
	int		i;

	c = malloc(t - f + 1);
	i = 0;
	while (f < t)
	{
		*(c + i) = str[f];
		i++;
		f++;
	}
	*(c + i) = '\0';
	return (c);
}

int	ft_count_element(char *str, char *charset)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	n = 0;
	while (str[i])
	{
		j = 0;
		while (charset[j] && str[i] != charset[j])
			j++;
		if (charset[j])
			n++;
		if (str[i + 1] == '\0' && charset[j] == '\0')
			n++;
		i++;
	}
	return (n);
}

char	**ft_fill_array(char *str, char *charset, char **result)
{
	int	i;
	int	j;
	int	c;
	int	n;

	i = 0;
	c = 0;
	n = 0;
	while (str[i])
	{
		j = 0;
		while (charset[j] && str[i] != charset[j])
			j++;
		if (charset[j] && i - c > 0)
			result[n++] = ft_strdup(c, i, str);
		if (charset[j])
			c = i + 1;
		if (str[i + 1] == '\0' && charset[j] == '\0')
			result[n++] = ft_strdup(c, i + 1, str);
		i++;
	}
	result[n] = 0;
	return (result);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;

	result = malloc(sizeof(char *) * (ft_count_element(str, charset) + 1));
	if (!result)
		return (0);
	return (ft_fill_array(str, charset, result));
}
