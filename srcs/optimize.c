/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_bsq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 11:38:37 by minhnguy          #+#    #+#             */
/*   Updated: 2019/08/28 22:04:42 by minhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	update_c_max(int *pc, int *prow, int *pmax)
{
	*pc = 0;
	*prow = 0;
	*pmax = 0;
}

int		no_obstacles(int row, int col, int d)
{
	int		max_d;

	max_d = g_res.max_y - col;
	if (is_in_bound(row + max_d, col + max_d))
		return (max(d, max_d));
	else
		return (d);
}

int		has_obstacles(t_obs *n_col, int row, int col, int max_d)
{
	row = 0;
	while (n_col->col < col && n_col->next_col)
		n_col = n_col->next_col;
	if (n_col->col < col)
		max_d = min(max_d, g_res.max_y - col);
	else
		max_d = min(max_d, n_col->col - col);
	return (max_d);
}

int		init_dimension(t_obs **begin, int row, int col)
{
	t_obs	*head;
	int		max_d;

	head = *begin;
	max_d = 0;
	while (head->row < row && head->next_row)
		head = head->next_row;
	if (head->row < row || head->row > row)
		max_d = g_res.max_y - col;
	else if (head->row == row)
		max_d = g_res.max_y - head->row;
	return (max_d);
}

int		find_dimension(int row, int col, int d)
{
	t_obs	*head;
	int		end;
	int		max_d;

	head = g_obs;
	if (head == 0)
		return (no_obstacles(row, col, d));
	max_d = init_dimension(&head, row, col);
	end = row + max_d;
	if (!is_in_bound(row + max_d, col + max_d))
		return (d);
	while (row < end)
	{
		if (head && head->row == row)
		{
			max_d = has_obstacles(head, row, col, max_d);
			if (head->next_row != 0)
				head = head->next_row;
		}
		else
			max_d = min(max_d, g_res.max_y - col);
		++row;
	}
	return (max(d, max_d));
}

void	update_result(int *p_dm, int row, int col)
{
	*p_dm += 1;
	save_result(row, col, *p_dm);
}

void	col_walk(int *p_row, int *p_col, int *p_d)
{
	int	tmp_max;

	if (!search_obs(&g_obs, *p_row, *p_col))
	{
		if (is_in_bound(*p_row + *p_d, *p_col + *p_d))
		{
			tmp_max = find_dimension(*p_row, *p_col, *p_d);
			if (tmp_max > *p_d)
			{
				*p_d = tmp_max;
				update_result(p_d, *p_row, *p_col);
			}
			if (g_obs->row == *p_row && g_obs->next_col)
			{
				g_obs = g_obs->next_col;
				*p_col = g_obs->col;
			}
		}
		else
			*p_col = *p_col + 1;
	}
	else
		*p_col = *p_col + 1;
}

void	find_bsq(char **board, int row, int col)
{
	int		c;
	int		max_dm;

	board = 0;
	update_c_max(&c, &row, &max_dm);
	row = 0;
	max_dm = 0;
	while (row < g_res.max_x - max_dm)
	{
		col = 0;
		while (col < g_res.max_y - max_dm)
		{
			col_walk(&row, &col, &max_dm);
		}
		++row;
		if (g_obs->next_row)
			g_obs = g_obs->next_row;
	}
}
