/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 16:04:30 by minhnguy          #+#    #+#             */
/*   Updated: 2019/08/28 15:51:15 by dtai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCT_H
# define FT_STRUCT_H

typedef struct		s_square
{
	int		start_x;
	int		start_y;
	int		dimension;
	int		max_x;
	int		max_y;
}					t_square;

typedef struct		s_obs
{
	int				row;
	int				col;
	struct s_obs	*next_row;
	struct s_obs	*next_col;
}					t_obs;

#endif
