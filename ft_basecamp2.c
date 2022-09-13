/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basecamp2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:09:00 by yoonsele          #+#    #+#             */
/*   Updated: 2022/09/13 16:05:38 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_info(t_info info)
{
	if (!(is_printable(info.emp) && is_printable(info.obs)
		&& is_printable(info.ful)))
		return (0);
	if (info.emp == info.obs || info.obs == info.ful
		|| info.ful == info.emp || info.line == 0)
		return (0);
	return (1);
}

int	ft_getinfo(int fd, t_info *info)
{
	char	c;

	while (read(fd, &c, 1) > 0 && is_num(c))
		info->line = info->line * 10 + c - '0';
	if (read(fd, &c, 1) > 0)
		info->emp = c;
	if (read(fd, &c, 1) > 0)
		info->obs = c;
	if (read(fd, &c, 1) > 0)
		info->ful = c;
	if (ft_check_info(*info))
		return (1);
	else
		return (0);
}
#include <stdio.h>
void	ft_basecamp(int fd)
{
	t_info	info;
//	char	**tab;
//	int		**d;
//	int		col;

	info.valid = 1;	//Q
	info.line = 0;	//Q
	if (ft_getinfo(fd, &info))		//get info of line, three char
	{	
		printf("check\n");
//		tab = ft_split(argv, "\n");
//		col = ft_validmap(tab, info, tmp);
//		d = ft_emptyd(info.line, col);
//		ft_print_tab(tab, info.line);
//		write(1, "\n", 1);
//		ft_print_tab(ft_dp(tab, d, info), info.line);
	}
}
// argv is string here!
