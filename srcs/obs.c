/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 15:46:29 by dtai              #+#    #+#             */
/*   Updated: 2019/08/28 22:00:59 by minhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_obs	*create_obs(int row, int col)
{
	t_obs	*obs;

	obs = malloc(sizeof(t_obs));
	obs->row = row;
	obs->col = col;
	obs->next_row = 0;
	obs->next_col = 0;
	return (obs);
}

void	add_obs(t_obs **begin_list, int row, int col)
{
	t_obs *temp;

	temp = *begin_list;
	if (temp)
	{
		while (temp->next_row && temp->row < row)
			temp = temp->next_row;
		if (temp->row < row)
		{
			temp->next_row = create_obs(row, col);
			return ;
		}
		while (temp->next_col)
			temp = temp->next_col;
		temp->next_col = create_obs(row, col);
	}
	else
		*begin_list = create_obs(row, col);
}

void	rm_obs(t_obs **begin_list)
{
	t_obs	*prev;
	t_obs	*curr;

	prev = *begin_list;
	curr = 0;
	if (prev->next_col)
	{
		curr = prev->next_col;
		curr->next_row = prev->next_row;
	}
	else if (prev->next_row)
	{
		curr = prev->next_row;
		curr->next_col = prev->next_col;
	}
	free(prev);
	*begin_list = curr;
}

int		search_obs(t_obs **begin_list, int row, int col)
{
	t_obs *temp;

	temp = *begin_list;
	while (temp->next_row && temp->row < row)
		temp = temp->next_row;
	if (temp != temp->next_row)
		return (0);
	while (temp->next_col && temp->col < col)
		temp = temp->next_col;
	if (temp != temp->next_col)
		return (0);
	return (1);
}
