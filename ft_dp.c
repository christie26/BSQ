/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmo <wmo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:14:11 by wmo               #+#    #+#             */
/*   Updated: 2022/09/13 00:25:33 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	min(int a, int b, int c)
{
	if (a > b)
		a = b;
	if (a > c)
		a = c;
	return (a);
}

int	**init_dp(char **tab, int **d, t_info info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info.line)
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == info.emp)
				d[i][j] = 1;
			else if (tab[i][j] == info.obs)
				d[i][j] = 0;
			j++;
		}
		i++;
	}
	return (d);
}

int	**ft_dpdp(char **tab, int **d, t_info *info, t_point *p)
{
	int	i;
	int	j;

	i = 1;
	while (i < info->line)
	{
		j = 1;
		while (tab[i][j])
		{
			if (tab[i][j] != info->obs && tab[i - 1][j - 1] != info->obs && \
					tab[i - 1][j] != info->obs && tab[i][j - 1] != info->obs)
			{
				d[i][j] = min(d[i - 1][j - 1], d[i - 1][j], d[i][j - 1]) + 1;
				if (d[i][j] > p->max)
				{
					p->max = d[i][j];
					p->max_row = i;
					p->max_col = j;
				}
			}
			j++;
		}
		i++;
	}
	return (d);
}

char	**ft_dp(char **tab, int **d, t_info info)
{
	int	i;
	int	j;
	t_point	p;

	p.max_row = 0;
	p.max_col = 0;
	p.max = 0;
	d = ft_dpdp(tab, d, &info, &p);
	i = p.max_row - p.max;
	while (i <= p.max_row)
	{
		j = p.max_col - p.max;
		while (j <= p.max_col)
		{
			tab[i][j] = info.ful;
			j++;
		}
		i++;
	}
	return (tab);
}
