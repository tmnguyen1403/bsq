/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_bsq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 11:38:37 by minhnguy          #+#    #+#             */
/*   Updated: 2019/08/27 20:56:13 by minhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		is_in_bound(int row, int col)
{
	if (row >= g_res.max_x || col >= g_res.max_y)
		return (0);
	return (1);
}

int		*init_solution(int max_dm)
{
	int		counter;
	int		*result;

	counter = 0;
	result = malloc(max_dm * sizeof(int));
	while (counter < max_dm)
	{
		result[counter] = 0;
		++counter;
	}
	return (result);
}

void	update_result(int *p_max, int row, int col, int *p_counter)
{
	*p_max += 1;
	save_result(row, col, *p_max);
	*p_counter += 1;
}

void	update_c_max(int *pc, int *prow, int *pmax)
{
	*pc = 0;
	*prow = 0;
	*pmax = 0;
}

void	find_bsq(char **board, int row, int col)
{
	int		*dm;
	int		c;
	int		max_dm;

	dm = init_solution(min(g_res.max_x, g_res.max_y));
	update_c_max(&c, &row, &max_dm);
	while (row < g_res.max_x - max_dm)
	{
		col = 0;
		while (col < g_res.max_y - max_dm)
		{
			if (c == 0)
				dm[0] = new_anchor(board, row, col, max_dm);
			else
				dm[c] = dm[c - 1] + check_board(board, row, col, max_dm);
			if (dm[c] == 0)
				update_result(&max_dm, row, col, &c);
			else
			{
				c = 0;
				++col;
			}
		}
		++row;
	}
}
