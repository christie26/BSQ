/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 20:04:02 by yoonsele          #+#    #+#             */
/*   Updated: 2022/09/14 20:33:17 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_tab(char **tab, t_info info)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (!(is_good(tab[i][j], info)))
				return (1);
			j++;
		}
		if (j != info.col)
			return (1);
		i++;
	}
	if (i != info.row)
		return (1);
	return (0);
}

int	ft_validmap(char **tab, t_info info)
{
	int	j;

	j = 0;
	while (tab[0][j])
	{
		if (!(is_good(tab[0][j], info)))
		{
			free(tab);
			error();
		}
		j++;
	}
	info.col = j;
	if (ft_check_tab(tab, info))
	{
		free(tab);
		error();
	}
	return (info.col);
}
