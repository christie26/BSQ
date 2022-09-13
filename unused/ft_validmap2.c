/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validmap2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:49:44 by yoonsele          #+#    #+#             */
/*   Updated: 2022/09/13 20:54:10 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_tab(char **tab, t_info info, int col)
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
			if (is_good(tab[i][j], info))
				return (1);
			j++;
		}
		if (j != col)
			return (1);
		i++;
	}
	if (i != info.row)
		return (1);
	return (0);
}

int	ft_fillmap(char **tab, t_info info, char *buf)
{
	int	j;
	int	col;

	j = 0;
	while (tab[0][j])
	{
		if (is_good(tab[0][j], info))
			info.valid = 0;
		j++;
	}
	col = j;
	if (ft_check_tab(tab, info, col) || info.valid == 0)
	{
		write(2, "map error\n", 10);
		free(buf);
		exit(1);
	}
	return (col);
}
