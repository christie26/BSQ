/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:13:23 by yoonsele          #+#    #+#             */
/*   Updated: 2022/09/12 17:36:54 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
# define FT_BSQ_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
	
# define FAIL_OPEN "Failed to open the file.\n"

void	ft_putchar(char c);
void	ft_putint(int nb);
void	ft_putnbr(int nb);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
char	**ft_split(char *str, char *charset);
void	ft_basecamp(char *buf);

typedef struct s_info
{
	char	emp;
	char	obs;
	char	ful;
	int		line;
	int		valid;
}	t_info;



#endif
