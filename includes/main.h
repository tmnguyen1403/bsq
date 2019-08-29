/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 11:52:33 by minhnguy          #+#    #+#             */
/*   Updated: 2019/08/28 22:06:12 by minhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAIN_H
# define FT_MAIN_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "ft_struct.h"
# include "helper_bsq.h"
# include "small_bsq.h"
# include "valid.h"
# include "read_stdin.h"
# include "obs.h"
# include "optimize.h"

char		g_empty;
char		g_obstacle;
char		g_full;
t_square	g_res;
t_obs		*g_obs;
#endif
