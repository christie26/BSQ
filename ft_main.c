/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:35:29 by yoonsele          #+#    #+#             */
/*   Updated: 2022/09/13 16:04:57 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
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
*/

int	main(int argc, char **argv)
{
	int	i;
	int	fd;

	if (argc == 1)
		ft_basecamp(0);
	else
	{
		i = 1;
		while (i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			if (fd < 0)	//when we fail to read it (non-exist file)
			{
				write(2, "map error\n", 10);
				return (0);	//Q
			}
			ft_basecamp(fd);
			close(fd);
			i++;
		}
	}
}
