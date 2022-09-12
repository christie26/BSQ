/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:35:29 by yoonsele          #+#    #+#             */
/*   Updated: 2022/09/12 17:35:32 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int argc, char **argv)
{
	int		fd1;
	int		fd2;
	int		len;
	char	c;
	char	*buf;

	(void) argc;
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[1], O_RDONLY);
	if (fd1 == -1 || fd2 == -1)
		ft_putstr(FAIL_OPEN);
	len = 0;
	while (read(fd1, &c, 1) > 0)
		len++;
	buf = (char *)malloc(len * sizeof(char));
	if (!buf)
		return (0);
	read(fd2, buf, len);
	ft_basecamp(buf);
	close(fd1);
	close(fd2);
	free(buf);
}
//maybe have to deal with null???
