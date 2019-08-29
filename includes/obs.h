/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obs.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 15:46:40 by dtai              #+#    #+#             */
/*   Updated: 2019/08/28 20:48:46 by dtai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBS_H
# define OBS_H

t_obs	*create_obs(int row, int col);
void	add_obs(t_obs **begin_list, int row, int col);
void	rm_obs(t_obs	**begin_list);
int		search_obs(t_obs **begin_list, int row, int col);

#endif
