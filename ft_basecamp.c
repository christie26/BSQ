/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basecamp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:09:00 by yoonsele          #+#    #+#             */
/*   Updated: 2022/09/12 17:35:47 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_num(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else
		return (0);
}

void	ft_checkinfo(int valid, char *buf)
{
	if (valid == 0)
	{
		write(2, "map error\n", 10);
		free(buf);
		exit (1);
	}
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
	if (info->emp == info->obs || info->obs == info->ful
		|| info->ful == info->emp || info->line == 0)
		info->valid = 0;
	if (*buf == '\n')
		buf++;
	else
		info->valid = 0;
	return (buf);
}

void	ft_basecamp(char *buf)
{
	t_info	info;
	char	**tab;
	char	*tmp;

	info.valid = 1;
	info.line = 0;
	tmp = buf;
	buf = ft_getinfo(buf, &info);
	ft_checkinfo(info.valid, tmp);
	tab = ft_split(buf, "\n");
	tmp_print_tab(tab, info.line);
}
