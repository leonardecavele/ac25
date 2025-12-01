/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 13:22:04 by ldecavel          #+#    #+#             */
/*   Updated: 2025/11/26 12:22:28 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <stdbool.h>
# include <unistd.h> 
# include <stdlib.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif
# if BUFFER_SIZE > 4096
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# define FD_MAX 1024

typedef struct s_rest
{
	char	b[BUFFER_SIZE];
	size_t	len;
	size_t	i;
}			t_rest;

typedef struct s_gnl
{
	char	*l;
	char	*dup;
	ssize_t	nread;
	size_t	cur;
	size_t	max;
}			t_gnl;

char	*get_next_line(int fd);

#endif
