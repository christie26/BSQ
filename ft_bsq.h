/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:13:23 by yoonsele          #+#    #+#             */
/*   Updated: 2022/09/13 16:05:26 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
# define FT_BSQ_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# define FAIL_OPEN "Failed to open the file.\n"

typedef struct s_info
{
	char	emp;
	char	obs;
	char	ful;
	int		line;
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
void	ft_basecamp(int fd);
int		ft_validmap(char **tab, t_info info, char *buf);
char	**ft_dp(char **tab, int **d, t_info info);
int		is_num(char c);
int		is_printable(char c);
void	ft_print_tab(char **tab, int line);

#endif
