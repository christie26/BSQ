/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:44:15 by yoonsele          #+#    #+#             */
/*   Updated: 2022/09/13 15:46:28 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_num(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else
		return (0);
}

int	is_printable(char c)
{
	if (31 < c && c < 127)
		return (1);
	else
		return (0);
}

void	ft_print_tab(char **tab, int line)
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
