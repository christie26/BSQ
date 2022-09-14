/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:32:11 by yoonsele          #+#    #+#             */
/*   Updated: 2022/09/14 22:07:25 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
# define FT_BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# define NEW_FILE "new file"

typedef struct s_info
{
	char	emp;
	char	obs;
	char	ful;
	int		row;
	int		col;
	int		flag;
}	t_info;

typedef struct s_point
{
	int	max_row;
	int	max_col;
	int	max;
}	t_point;

char	**ft_split(char *str, char *charset);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
int		ft_validmap(char **tab, t_info info);
int		is_printable(char c);
int		is_good(char c, t_info info);
int		is_num(char c);
void	error(void);
void	error1(void);
int		**ft_make_d(t_info info);
void	ft_print_tab(char **tab, int line);
char	**ft_dp(char **tab, int **d, t_info info);
char	*ft_getfl(char *buf, t_info *info);
int		ft_check_info(t_info info);
void	free_tab(char **tab);
void	free_d(int **tab);

#endif
