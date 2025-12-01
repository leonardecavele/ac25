/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:32:09 by ldecavel          #+#    #+#             */
/*   Updated: 2025/12/01 18:50:25 by ldecavel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int	decrypt(int c, int n, int mode)
{
	static int	dial = 50;
	int			iter_on_zero = 0;

	while (n--)
	{
		if (c == 'L')
			dial--;
		else
			dial++;
		if (dial == 100)
			dial = 0;
		if (dial == -1)
			dial = 99;
		if (dial == 0 && mode == 'b')
			iter_on_zero++;
	}
	if (mode == 'a' && dial == 0)
		return (1);
	return (iter_on_zero);
}

int	main(int ac, char **av)
{
	int		fd;
	int		res = 0;
	char	*s;

	if (ac != 3 || !(av[2][0] == 'a' || av[2][0] == 'b'))
	{
		dprintf(2, "Please use three arguments\n");
		dprintf(2, "usage: ./ac1 input a | ./ac1 input b\n");
		return (1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (1);
	while ((s = get_next_line(fd)))
	{
		if (s[0] != 'L' && s[0] != 'R')
		{
			dprintf(2, "Wrong input file\n");
			free(s);
			return (1);
		}
		res += decrypt(s[0], atoi(&s[1]), av[2][0]);
		free(s);
	}
	printf("%d\n", res);
	close(fd);
	return (0);
}
