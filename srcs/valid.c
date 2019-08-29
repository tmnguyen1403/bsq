/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 01:32:33 by dtai              #+#    #+#             */
/*   Updated: 2019/08/28 22:16:10 by minhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	check_col(char *file_name, int access)
{
	int		nb_col;
	char	c;
	int		new_lines;

	close(access);
	access = open(file_name, O_RDONLY);
	nb_col = 0;
	new_lines = 0;
	while (read(access, &c, 1))
	{
		if (c == '\n')
		{
			if (new_lines == 0)
			{
				new_lines = 1;
				continue ;
			}
			else
				break ;
		}
		if (new_lines == 1)
			nb_col++;
	}
	g_res.max_y = nb_col;
	close(access);
}

int		find_n_line(char *f_line, int len)
{
	int itr;
	int counter;

	itr = 0;
	counter = -1;
	while (itr < len)
	{
		if (f_line[itr] == '\n')
		{
			counter = itr;
			break ;
		}
		itr++;
	}
	if ((counter >= -1 && counter <= 3) || counter > 13)
		return (0);
	return (counter);
}

int		check_f_line(char *file_name, char *f_line, int f_line_len, int access)
{
	int		len;
	int		itr;
	int		nb_row;

	if (!(len = find_n_line(f_line, f_line_len)))
		return (0);
	itr = -1;
	nb_row = 0;
	while (++itr < len - 3)
	{
		if (nb_row == 214748364 && (f_line[itr] == '8' || f_line[itr] == '9'))
			return (0);
		if (f_line[itr] >= '0' && f_line[itr] <= '9')
			nb_row = nb_row * 10 + (f_line[itr] - '0');
		else
			return (0);
	}
	g_res.max_x = nb_row;
	g_empty = f_line[len - 3];
	g_obstacle = f_line[len - 2];
	g_full = f_line[len - 1];
	if (g_empty == g_obstacle)
		return (0);
	check_col(file_name, access);
	return (access);
}

int		valid(char *file_name)
{
	int		access;
	char	*f_line;
	int		f_line_len;
	char	c;

	f_line = malloc(sizeof(char) * 20);
	access = open(file_name, O_RDONLY);
	if (access < 0)
		return (0);
	while (read(access, &c, 1))
	{
		if (c != '0')
		{
			f_line[0] = c;
			break ;
		}
	}
	f_line_len = read(access, &f_line[1], 19) + 1;
	access = check_f_line(file_name, f_line, f_line_len, access);
	free(f_line);
	return (access);
}
