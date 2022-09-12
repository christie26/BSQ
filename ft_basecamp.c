/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basecamp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:09:00 by yoonsele          #+#    #+#             */
/*   Updated: 2022/09/12 23:28:51 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_num(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else
		return (0);
}

void	tmp_print_tab(char **tab, int line)
{
	int	i;

	i = 0;
	while (i < line)
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}
}

char	*ft_getinfo(char *buf, t_info *info)
{
	while (is_num(*(buf)))
	{
		info->line = info->line * 10 + *buf - '0';
		buf++;
	}
	info->emp = *(buf++);
	info->obs = *(buf++);
	info->ful = *(buf++);
	if (*buf == '\n')
		buf++;
	else
		info->valid = 0;
	return (buf);
}

char	**ft_emptyd(int row, int col)
{
	char	**d;
	int		i;

	d = (char **)malloc(sizeof(char *) * row);
	i = 0;
	while (i < row)
	{
		d[i] = (char *)malloc(sizeof(char) * col);
		i++;
	}
	return (d);
}

void	ft_basecamp(char *buf)
{
	t_info	info;
	char	**tab;
	char	**d;
	char	*tmp;
	int		col;

	info.valid = 1;
	info.line = 0;
	tmp = buf;
	buf = ft_getinfo(buf, &info);
	tab = ft_split(buf, "\n");
	col = ft_validmap(tab, info, tmp);
	d = ft_emptyd(info.line, col);
	tmp_print_tab(tab, info.line);
//	ft_wmo(tab, info, d);
}
// ft_wmo(char **tab, int **d, t_info info);
// d is empty 2 dimension int array whose size is same as tab.
