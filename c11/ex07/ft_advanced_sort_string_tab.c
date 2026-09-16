/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kelk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 10:47:48 by sel-kelk          #+#    #+#             */
/*   Updated: 2026/09/02 10:56:19 by sel-kelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	int		j;
	char	*c;

	i = 0;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (cmp(tab[i], tab[j]) > 0)
			{
				c = *(tab + i);
				*(tab + i) = *(tab + j);
				*(tab + j) = c;
			}
			j++;
		}
		i++;
	}
}
