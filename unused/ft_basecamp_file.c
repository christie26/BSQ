/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basecamp_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 22:05:09 by yoonsele          #+#    #+#             */
/*   Updated: 2022/09/13 22:26:29 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_basecamp_file(int fd, int fl, int col)
{
	t_info	info;
	char	buf[fl];

	info.col = col;
	read(fd, &buf, fl);
	ft_getinfo(fl, buf, &info);
}
