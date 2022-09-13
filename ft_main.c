/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:35:29 by yoonsele          #+#    #+#             */
/*   Updated: 2022/09/13 22:43:47 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_read_two(char *argv, int *fl, int *col)
{
	char	c;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		exit (1);
	}
	*fl = 0;
	*col = 0;
	while (read(fd, &c, 1) > 0 && c != '\n')
		(*fl)++;
	while (read(fd, &c, 1) > 0 && c != '\n')
		(*col)++;
	close(fd);
}

int	main(int argc, char **argv)
{
	int	i;
	int	fd;
	int	fl;
	int	col;

	if (argc == 1)
		ft_basecamp_input();
	else
	{
		i = 1;
		while (i < argc)
		{
			ft_read_two(argv[i], &fl, &col);	
			fd = open(argv[i], O_RDONLY);
			if (fd < 0)
			{
//				write(2, "map error\n", 10); or wrong file?
				return (0);//Q
			}
			ft_basecamp_file(fd, fl, col);
			close(fd);
			i++;
		}
	}
}
