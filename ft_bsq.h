/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:13:23 by yoonsele          #+#    #+#             */
/*   Updated: 2022/09/14 17:59:11 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
# define FT_BSQ_H

#include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_info
{
	char	emp;
	char	obs;
	char	ful;
	int		row;
	int		col;
	int		valid;
}	t_info;

typedef struct s_point
{
	int	max_row;
	int	max_col;
	int	max;
}	t_point;

void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
char	**ft_split(char *str, char *charset);
void	ft_basecamp_file(int fd, int fl, int col);
void	ft_basecamp_input(void);
int		ft_validmap(char **tab, t_info info, char *buf);
char	**ft_dp(char **tab, int **d, t_info info);
int		is_num(char c);
int		is_printable(char c);
int		is_good(char c, t_info info);
void	ft_print_tab(char **tab, int line);
int		ft_atoi(char *str);
char	*ft_strcpy(char *dest, char *src);
char	**make_table(t_info info);
int		**make_d(t_info info);
void	error(void);
void	ft_getinfo(int size, char *buf, t_info *info);
int		ft_fill_line(int fd, char **taab, int i, t_info info);

#endif
