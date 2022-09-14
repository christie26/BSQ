/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:11:18 by yoonsele          #+#    #+#             */
/*   Updated: 2022/09/14 22:10:03 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_print_answer(char **tab, t_info info)
{
	int		**d;

	if (info.flag || ft_check_info(info))
	{
		free_tab(tab);
		error();
	}
	info.col = ft_validmap(tab, info);
	d = ft_make_d(info);
	tab = ft_dp(tab, d, info);
	free_d(d);
	ft_print_tab(tab, info.row);
	free_tab(tab);
}

void	make_buffer(char *filename, int len)
{
	int		fd;
	char	*buf;
	char	*tmp;
	char	**tab;
	t_info	info;

	buf = (char *)malloc(sizeof(char) * (len + 1));
	if (!buf)
		return ;
	fd = open(filename, O_RDONLY);
	read(fd, buf, len);
	buf[len] = 0;
	close(fd);
	tmp = buf;
	buf = ft_getfl(buf, &info);
	tab = ft_split(buf, "\n");
	free(tmp);
	ft_print_answer(tab, info);
}

void	get_stdin(void)
{
	int		fd;
	char	c;
	int		i;

	i = 0;
	fd = open(NEW_FILE, O_WRONLY | O_CREAT, 0644);
	while (read(STDIN_FILENO, &c, 1) != 0)
	{
		write(fd, &c, 1);
		i++;
	}
	close (fd);
	make_buffer(NEW_FILE, i);
}

int	main(int argc, char **argv)
{
	int		fd;
	int		i;
	int		len;
	char	c;

	if (argc == 1)
		get_stdin();
	else
	{
		i = 1;
		while (i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			if (fd == -1)
				return (1);
			len = 0;
			while (read(fd, &c, 1) > 0)
				len++;
			close(fd);
			make_buffer(argv[i], len);
			i++;
		}
	}	
}
