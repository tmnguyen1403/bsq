/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_bsq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 11:38:37 by minhnguy          #+#    #+#             */
/*   Updated: 2019/08/28 22:03:49 by minhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		check_board(char **board, int row, int col, int n)
{
	int		counter;

	if (n == 0)
		return (is_empty(board[row][col]));
	else
	{
		if (!is_in_bound(row + n, col + n))
			return (1);
		counter = 0;
		while (counter <= n)
		{
			if (!is_empty(board[row + n][col + counter]))
				return (1);
			if (!is_empty(board[row + counter][col + n]))
				return (1);
			++counter;
		}
	}
	return (0);
}

int		new_anchor(char **board, int x, int y, int n)
{
	int		row;
	int		col;

	if (!is_in_bound(x + n, y + n))
		return (1);
	row = x;
	while (row <= x + n)
	{
		col = y;
		while (col <= y + n)
		{
			if (!is_empty(board[row][col]))
				return (1);
			++col;
		}
		++row;
	}
	return (0);
}

void	save_result(int x, int y, int d)
{
	g_res.start_x = x;
	g_res.start_y = y;
	g_res.dimension = d;
}

char	*create_str_with(char c, int len)
{
	char	*result;
	int		row;

	result = 0;
	if (len > 0)
		result = malloc(len * sizeof(char));
	row = 0;
	while (row < len)
	{
		result[row] = c;
		++row;
	}
	return (result);
}

void	print_result(char **board)
{
	int		row;
	int		len;
	int		full_x;
	char	*s_full;

	full_x = g_res.start_x + g_res.dimension;
	len = g_res.max_y + 1 - (g_res.start_y + g_res.dimension);
	s_full = create_str_with(g_full, g_res.dimension);
	row = 0;
	while (row < g_res.max_x)
	{
		if (row >= g_res.start_x && row < full_x && s_full != 0)
		{
			write(1, board[row], g_res.start_y);
			write(1, s_full, g_res.dimension);
			write(1, board[row] + g_res.start_y + g_res.dimension, len);
		}
		else
			write(1, board[row], g_res.max_y + 1);
		++row;
	}
	if (s_full)
		free(s_full);
}
