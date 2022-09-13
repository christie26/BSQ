/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 20:42:49 by yoonsele          #+#    #+#             */
/*   Updated: 2022/09/09 08:29:38 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	check_set(char *str, char *charset, int i)
{
	int	j;

	j = -1;
	while (charset[++j])
	{
		if (charset[j] == str[i])
			return (1);
	}
	return (0);
}

char	*ft_malloc(char **tab, char *str, char *charset, int i)
{
	int	j;
	int	size;
	int	set;

	j = 0;
	size = 0;
	set = 0;
	while (check_set(str, charset, j) == 1 && str[j++])
		set++;
	while (check_set(str, charset, j) == 0 && str[j++])
		size++;
	tab[i] = (char *)malloc((size + 1) * sizeof(char));
	if (!tab[i])
		return (0);
	str += set;
	j = -1;
	while (++j < size)
		tab[i][j] = str[j];
	tab[i][j] = 0;
	str += size;
	return (str);
}

int	ft_size(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (check_set(str, charset, i) && str[i])
			i++;
		if (check_set(str, charset, i) == 0 && str[i])
			count++;
		while (check_set(str, charset, i) == 0 && str[i])
			i++;
	}
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		size;
	int		i;

	size = ft_size(str, charset);
	size++;
	tab = (char **)malloc(size * sizeof(char *));
	if (!tab)
		return (0);
	i = -1;
	while (++i < size - 1)
		str = ft_malloc(tab, str, charset, i);
	tab[i] = 0;
	return (tab);
}
