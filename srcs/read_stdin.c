/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 13:41:05 by minhnguy          #+#    #+#             */
/*   Updated: 2019/08/28 12:50:22 by minhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		read_stdin(char *fname)
{
	int		fd;
	char	*str;
	int		size;
	int		ret;

	fd = open(fname, O_CREAT, 0666);
	close(fd);
	fd = open(fname, O_TRUNC);
	close(fd);
	fd = open(fname, O_WRONLY);
	if (fd < 0)
		return (0);
	size = 10000;
	str = malloc(size * sizeof(char));
	while ((ret = read(0, str, size)))
	{
		write(fd, str, ret);
	}
	close(fd);
	free(str);
	return (1);
}
