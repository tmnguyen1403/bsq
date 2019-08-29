/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_bsq.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 19:07:43 by minhnguy          #+#    #+#             */
/*   Updated: 2019/08/28 15:55:34 by dtai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPER_BSQ_H
# define HELPER_BSQ_H

int		check_board(char **board, int row, int col, int n);
int		new_anchor(char **board, int x, int y, int n);
void	save_result(int x, int y, int d);
char	*create_str_with(char c, int len);
void	print_result(char **board);
#endif
