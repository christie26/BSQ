/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 20:05:06 by yoonsele          #+#    #+#             */
/*   Updated: 2022/09/14 20:47:24 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_printable(char c)
{
	if (31 < c && c < 127)
		return (1);
	else
		return (0);
}

int	is_good(char c, t_info info)
{
	if (c == info.emp || c == info.obs)
		return (1);
	else
		return (0);
}

int	is_num(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else
		return (0);
}

void	error(void)
{
	write(2, "map error\n", 10);
	exit (1);
}
