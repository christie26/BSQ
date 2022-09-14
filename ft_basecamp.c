/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basecamp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:09:00 by yoonsele          #+#    #+#             */
/*   Updated: 2022/09/14 18:36:51 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_check_line(char *str, t_info info)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
	{
		if (!(is_good(str[i], info)))
			error();
		i++;
	}
}

void	ft_basecamp_file(int fd, int fl, int col)
{
	t_info	info;
	char	*buf;
	int		i;
	char	**tab;
	int		**d;
	char	c;

	buf = (char *)malloc(sizeof(char) * (fl));
	if (!buf)
		return ;
	read(fd, buf, fl);
	ft_getinfo(fl, buf, &info);
	info.col = col;
	tab = make_table(info);
	i = 0;
	read(fd, &c, 1);
	while (i < info.row)
	{
		ft_fill_line(fd, tab, i, info);
		i++;
	}
	d = make_d(info);
	tab = ft_dp(tab, d, info);
	ft_print_tab(tab, info.row);
}

void	ft_basecamp_input(void)
{
	t_info	info;
	char	buf1[4096];
	char	buf2[4096];
	int		i;
	char	**tab;
	int		**d;
	char	c;

	read(STDIN_FILENO, buf1, sizeof(buf1));
	i = 0;
	while (buf1[i] != '\n')
		i++;
	ft_getinfo(i, buf1, &info);
	read(STDIN_FILENO, buf2, sizeof(buf2));
	i = 0;
	while (buf2[i] != '\n')
		i++;
	info.col = i;
	ft_check_line(buf2, info);
	tab = make_table(info);
	ft_strcpy(tab[0], buf2);
	i = 1;
	while (i < info.row)
	{
		ft_fill_line(STDIN_FILENO, tab, i, info);
		i++;
	}
	read(STDIN_FILENO, &c, 1);
	if (c != EOF)
		ft_putstr("ee");
//	while (ft_fill_line(STDIN_FILENO, tab, i, info) == 1)
//		i++;
//	if (i == info.row)
//	{
		d = make_d(info);
		tab = ft_dp(tab, d, info);
		ft_print_tab(tab, info.row);
//	}
//	else
//		ft_putstr("happy");
//		error();
}
