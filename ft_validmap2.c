/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validmap2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:49:44 by yoonsele          #+#    #+#             */
/*   Updated: 2022/09/13 16:04:00 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isgood(char c, t_info info)
{
	if (c == info.emp || c == info.obs)
		return (0);
	else
		return (1);
}

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
			if (ft_isgood(tab[i][j], info))
				return (1);
			j++;
		}
		if (j != col)
			return (1);
		i++;
	}
	if (i != info.line)
		return (1);
	return (0);
}

int	ft_validmap(char **tab, t_info info, char *buf)
{
	int	j;
	int	col;

	j = 0;
	while (tab[0][j])
	{
		if (ft_isgood(tab[0][j], info))
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
