/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:32:09 by ldecavel          #+#    #+#             */
/*   Updated: 2025/12/01 12:55:04 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int	decrypt(int c, int n)
{
	static int	dial = 50;

	if (c == 'L')
		dial += n;
	else if (c == 'R')
		dial -= n;
	else
	{
		dprintf(2, "Wrong file\n");
		exit(1);
	}
	return (dial % 100);
}

int	main(int ac, char **av)
{
	int		fd;
	int		res = 0;
	char	*s;

	if (ac != 2)
	{
		dprintf(2, "Please use two arguments\n");
		return (1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (1);
	while ((s = get_next_line(fd)))
	{
		if (decrypt(s[0], atoi(&s[1])) == 0)
			res++;
		free(s);
	}
	printf("%d\n", res);
	close(fd);
	return (0);
}
