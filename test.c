/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmo <wmo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:14:11 by wmo               #+#    #+#             */
/*   Updated: 2022/09/12 22:56:48 by wmo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//typedef	struct 
//{



//}t_info;

int	**init_dp(char **tab, int **d, t_info info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info.line)
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == info.emp)
				d[i][j] = 1;
			else if (tab[i][j] == info.obs)
				d[i][j] = 0;
			j++;
		}
		i++;
	}
	return (d);
}



char	**ft_dp(char **tab, int **d, t_info info)
{

	int	i;
	int	j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (str[i][j])
		{
			if (i == 0)
			{
				j++;
				continue;
			}
			if (str[i][j] != 'o' && str[i-1][j-1] != 'o' && str[i-1][j] != 'o' && str[i][j-1] != 'o')
			{
				d[i][j] = min(d[i-1][j-1], d[i-1][j], d[i][j-1]) + 1;
				if (d[i][j] > max)
				{
					max = d[i][j];
					max_row = i;
					max_col = j;
				}
			}

			j++;
		}
		i++;
	}
	printf("maxrow:%d maxcol:%d\n\n", max_row, max_col);
	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 27)
		{
			printf("%d ", d[i][j]);
			j++;
		}
		printf("\n\n");
		i++;
	}


}





}
#include <stdio.h>
#include <stdlib.h>
int min(int a, int b, int c)
{
	if (a > b)
		a = b;
	if (a > c)
		a = c;
	return (a);
}

int main() {


	char **str;
	int	**d;
	int i = 0;
	int j = 0;
	str = (char **)malloc(sizeof(char *) * 20);
	d   = (int **)malloc(sizeof(int *)* 20);
	int max = -1;
	int max_row = 0;
	int max_col = 0;

	while (i < 9)
	{
		str[i] = (char *)malloc(sizeof(char ) * 100);
		d[i] = (int *)malloc(sizeof(int) * 100);
		i++;
	}

	str[0] = "...........................";
	str[1] = "....o......................";
	str[2] = "............o..............";
	str[3] = "...........................";
	str[4] = "....o......................";
	str[5] = "...............o...........";
	str[6] = "...........................";
	str[7] = "......o..............o.....";
	str[8] = "..o.......o................";

	i = 0;
	//dp 배열 초기화 <- 추후 함수로 만들기
	while (i < 9)
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '.')
				d[i][j] = 1;
			else if (str[i][j] == 'o')
				d[i][j] = 0;
			j++;
		}
		i++;
	}
	i = 0;
	//dp 배열에 최댓값 넣어주기 <- 추후 함수로 만들기
	while (i < 9)
	{
		j = 0;
		while (str[i][j])
		{
			if (i == 0)
			{
				j++;
				continue;
			}
			if (str[i][j] != 'o' && str[i-1][j-1] != 'o' && str[i-1][j] != 'o' && str[i][j-1] != 'o')
			{
				d[i][j] = min(d[i-1][j-1], d[i-1][j], d[i][j-1]) + 1;
				if (d[i][j] > max)
				{
					max = d[i][j];
					max_row = i;
					max_col = j;
				}
			}

			j++;
		}
		i++;
	}
	printf("maxrow:%d maxcol:%d\n\n", max_row, max_col);
	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 27)
		{
			printf("%d ", d[i][j]);
			j++;
		}
		printf("\n\n");
		i++;
	}


}
