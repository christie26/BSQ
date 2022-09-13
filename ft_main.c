/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:35:29 by yoonsele          #+#    #+#             */
/*   Updated: 2022/09/13 15:14:23 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_get_input(void)
{
	char	*buf;
	read(0, &buf, 10000);
	return (buf);
}

char	*ft_read_file(int i, char **argv)
{
	int		fd1;
	int		fd2;
	int		len;
	char	c;
	char	*buf;

	fd1 = open(argv[i], O_RDONLY);
	fd2 = open(argv[i], O_RDONLY);
	if (fd1 == -1 || fd2 == -1)
	{
		write(2, "map error\n", 10);
		exit (1);
	}
	else
	{
		len = 0;
		while (read(fd1, &c, 1) > 0)
			len++;
		close(fd1);
		buf = (char *)malloc(len * sizeof(char));
		if (!buf)
			return (0);
		read(fd2, buf, len);
		close(fd2);
	}
	return (buf);
}

int	main(int argc, char **argv)
{
	int		i;
	char	*buf;

	if (argc == 1)
		buf = ft_get_input();
	else
	{
		i = 1;
		while (i < argc)
		{
			buf = ft_read_file(i, argv);
			ft_basecamp(buf);
			free(buf);
			i++;
		}
	}
}
