/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_bsq.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 19:13:54 by minhnguy          #+#    #+#             */
/*   Updated: 2019/08/26 19:19:22 by minhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIND_BSQ_H
# define FIND_BSQ_H

int		is_in_bound(int row, int col);
int		min(int a, int b);
int		*init_solution(int max_dm);
int		is_empty(char c);
void	find_bsq(char **board, int x, int y);
#endif
