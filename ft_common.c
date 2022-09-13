/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_common.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 22:09:59 by yoonsele          #+#    #+#             */
/*   Updated: 2022/09/13 23:30:43 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	**make_table(t_info info)
{
	char	**tab;
	int		i;

	tab = (char **)malloc(sizeof(char *) * (info.row + 1));
	if (!tab)
		return (0);
	i = 0;
	while (i < info.row)
	{
		tab[i] = (char *)malloc(sizeof(char) * (info.col + 1));
		if (!(tab[i]))
			return (0);
		i++;
	}
	return (tab);
}

int	**make_d(t_info info)
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

int	ft_check_info(t_info info)
{
	if (!(is_printable(info.emp) && is_printable(info.obs)
			&& is_printable(info.ful)))
		return (0);
	if (info.emp == info.obs || info.obs == info.ful
		|| info.ful == info.emp || info.row == 0)
		return (0);
	return (1);
}

void	ft_getinfo(int size, char *buf, t_info *info)
{
	int		i;

	info->emp = buf[size - 3];
	info->obs = buf[size - 2];
	info->ful = buf[size - 1];
	buf[size - 3] = '\0';
	i = 0;
	info->row = 0;
	while (is_num(buf[i]))
	{
		info->row = info->row * 10 + buf[i] - '0';
		i++;
	}
	if (i == size - 3 && ft_check_info(*info))
		return ;
	else
		error();
}

void	ft_fill_line(int fd, char **tab, int i, t_info info)
{
	int		j;
	char	c;

	j = 0;

	while (j < info.col)
	{
		if (read(fd, &tab[i][j], 1) > 0 && is_good(tab[i][j], info))
			j++;
		else
			error();
	}
	read (fd, &c, 1);
	if (c != '\n')
		error();
}
