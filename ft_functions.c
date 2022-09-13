/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:48:49 by yoonsele          #+#    #+#             */
/*   Updated: 2022/09/12 23:27:00 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	ft_min(int a, int b, int c)
{
	if (a > b)
		a = b;
	if (a > c)
		a = c;
	return (a);
}

void	ft_putnbr(int nb)
{
	unsigned int	new;
	int				mod;
	char			c;

	if (nb < 0)
	{
		new = -nb;
		write(1, "-", 1);
	}
	else
		new = nb;
	mod = new % 10;
	if (new >= 10)
	{
		new /= 10;
		ft_putnbr(new);
	}
	c = mod + '0';
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
