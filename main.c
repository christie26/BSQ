/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:09:00 by yoonsele          #+#    #+#             */
/*   Updated: 2022/09/12 16:36:26 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_num(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else
		return (0);
}

t_info	ft_getinfo(char *buf)
{
	t_info	info;
	char	**tab;

	info.valid = 1;
	info.line = 0;
	while (is_num(*(buf)))
	{
		info.line = info.line * 10 + *buf - '0';
		buf++;
	}
	info.emp	= *(buf++);
	info.obs	= *(buf++);
	info.ful	= *(buf++);
	if (info.emp == info.obs || info.obs == info.ful || info.ful == info.emp)
		info.valid = 0;
	if (*buf == '\n')
		buf++;
	else
		info.valid = 0;
	printf("%d,%c,%c,%c\n", info.line, info.emp, info.obs, info.ful);
	tab = ft_split(buf, "\n");
	int	i = 0;
	while (i < info.line)
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}
	return (info);
}

int	main(int argc, char **argv)
{
	int		fd1;
	int		fd2;
	int		len;
	char	c;
	char	*buf;
//	char	**tab;
	t_info	info;
	
	(void) argc;	// have to deal with this when we take care n files
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[1], O_RDONLY);
	if (fd1 == -1 || fd2 == -1)
		ft_putstr(FAIL_OPEN);
	len = 0;
	while (read(fd1, &c, 1) > 0)
	{
//		write(1, &c, 1);
		len++;
	}
	printf("len is %d\n", len);
	buf = (char*)malloc(len * sizeof(char));	// space for null? or not
	if(!buf)
		return (0);
	read(fd2, buf, len);
	info = ft_getinfo(buf);
//	printf("%s\n", info.buf);
/*
	while (i++ < info.line)
	{
		write(1, &tab[i], 20);
		write(1, "\n", 1);
		i++;
	}*/
	free(buf);
}
