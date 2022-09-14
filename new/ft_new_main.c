/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:11:18 by yoonsele          #+#    #+#             */
/*   Updated: 2022/09/14 20:48:18 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_check_info(t_info info)
{
	if (!(is_printable(info.emp) && is_printable(info.obs)
			&& is_printable(info.ful)))
		error();
	if (info.emp == info.obs || info.obs == info.ful
		|| info.ful == info.emp || info.row == 0)
		error();
	return ;
}

int	ft_getinfo(char *fl, int len, t_info *info)
{
	int	i;

	info->emp = fl[len - 3];
	info->obs = fl[len - 2];
	info->ful = fl[len - 1];
	fl[len - 3] = '\0';
	i = 0;
	info->row = 0;
	while (is_num(fl[i]))
	{
		info->row = info->row * 10 + fl[i] - '0';
		i++;
	}
	free(fl);
	if (i != len - 3)
		return (1);
	else
		return (0);
}

char	*ft_getfl(char *buf, t_info *info, int *flag)
{
	int		i;
	int		len;
	char	*fl;

	i = 0;
	while (buf[i] != '\n')
		i++;
	len = i;
	fl = (char *)malloc(sizeof(char) * (len + 1));
	if (!fl)
		return (0);
	ft_strncpy(fl, buf, len);
	*flag = 0;
	if (ft_getinfo(fl, len, info))
		*flag = 1;
	buf += len;
	return (buf);
}

void	make_buffer(char *filename, int len)
{
	int		fd;
	int		flag;
	char	*buf;
	char	*tmp;
	char	**tab;
	int		**d;
	t_info	info;

	buf = (char *)malloc(sizeof(char) * (len + 1));
	if (!buf)
		return ;//Q
	fd = open(filename, O_RDONLY);
	read(fd, buf, len);
	buf[len] = 0;
	close(fd);
	tmp = buf;
	buf = ft_getfl(buf, &info, &flag);
	tab = ft_split(buf, "\n");
	free(tmp);
	if (flag)
		error();
	ft_check_info(info);
	info.col = ft_validmap(tab, info);
	d = ft_make_d(info);
	tab = ft_dp(tab, d, info);
	ft_print_tab(tab, info.row);
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
				return (1);// Q
			len = 0;
			while (read(fd, &c, 1) > 0)
				len++;
			close(fd);
			make_buffer(argv[i], len);
			i++;
		}
	}	
}
