/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 20:23:33 by yoonsele          #+#    #+#             */
/*   Updated: 2022/09/14 20:47:38 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	**ft_make_d(t_info info)
{
	int	**tab;
	int	i;

	tab = (int **)malloc(sizeof(int *) * (info.row + 1));
	if (!tab)
		return (0);
	i = 0;
	while (i < info.row)
	{
		tab[i] = (int *)malloc(sizeof(int) * (info.col + 1));
		if (!(tab[i]))
			return (0);
		i++;
	}
	return (tab);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_print_tab(char **tab, int line)
{
	int	i;

	i = 0;
	while (i < line)
	{
		ft_putstr(tab[i]);
		write(1, "\n", 1);
		i++;
	}
}
