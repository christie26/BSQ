/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 20:04:02 by yoonsele          #+#    #+#             */
/*   Updated: 2022/09/14 21:59:54 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_info(t_info info)
{
	if (!(is_printable(info.emp) && is_printable(info.obs)
			&& is_printable(info.ful)))
		return (1);
	if (info.emp == info.obs || info.obs == info.ful
		|| info.ful == info.emp || info.row == 0)
		return (1);
	return (0);
}

int	ft_getinfo(char *fl, int len, t_info *info)
{
	int	i;

	info->emp = fl[len - 3];
	info->obs = fl[len - 2];
	info->ful = fl[len - 1];
	fl[len - 3] = '\0';
	i = 0;
	info->row = 0;
	while (is_num(fl[i]))
	{
		info->row = info->row * 10 + fl[i] - '0';
		i++;
	}
	free(fl);
	if (i != len - 3)
		return (1);
	else
		return (0);
}

char	*ft_getfl(char *buf, t_info *info)
{
	int		i;
	int		len;
	char	*fl;

	i = 0;
	while (buf[i] != '\n')
		i++;
	len = i;
	fl = (char *)malloc(sizeof(char) * (len + 1));
	if (!fl)
		return (0);
	ft_strncpy(fl, buf, len);
	info->flag = 0;
	if (ft_getinfo(fl, len, info))
		info->flag = 1;
	buf += len;
	return (buf);
}

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
