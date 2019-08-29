/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 10:15:25 by dtai              #+#    #+#             */
/*   Updated: 2019/08/28 21:43:54 by dtai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		check_char(char *str, int row)
{
	int		itr;

	itr = 0;
	while (str[itr] != '\n')
	{
		if (str[itr] != g_empty && str[itr] != g_obstacle)
			return (0);
		if (str[itr] == g_obstacle)
		{
			if (g_obs == 0)
				g_obs = create_obs(row, itr);
			else
				add_obs(&g_obs, row, itr);
		}
		itr++;
	}
	return (1);
}

char	**free_board(char ***p, int row)
{
	char	**board;
	int		counter;

	board = *p;
	counter = 0;
	while (counter < row)
	{
		free(board[counter]);
		counter++;
	}
	free(board);
	*p = 0;
	return (NULL);
}

char	**malloc_board(int row, int col, int access)
{
	int		itr;
	char	c;
	char	**board;

	while (read(access, &c, 1))
	{
		if (c == '\n')
			break ;
	}
	board = malloc(sizeof(char *) * row);
	itr = 0;
	while (itr < row)
	{
		board[itr] = malloc(sizeof(char) * col);
		read(access, board[itr], col);
		if (board[itr][col - 1] != '\n' || !check_char(board[itr], itr))
			return (free_board(&board, itr + 1));
		itr++;
	}
	if (read(access, &c, 1) != 0)
		return (free_board(&board, itr));
	return (board);
}

void	handle_file(char *fname)
{
	char	**board;
	int		access;

	g_res.start_x = -1;
	g_res.start_y = -1;
	g_res.dimension = -1;
	g_obs = 0;
	access = valid(fname);
	if (access > 0)
	{
		access = open(fname, O_RDONLY);
		board = malloc_board(g_res.max_x, g_res.max_y + 1, access);
		if (!board)
		{
			write(1, "map error\n", 10);
			return ;
		}
		find_bsq(board, 0, 0);
		print_result(board);
		board = free_board(&board, g_res.max_x);
	}
	else
		write(1, "map error\n", 10);
}

int		main(int argc, char **argv)
{
	char	*fname;
	int		status;
	int		itr;

	if (argc <= 1)
	{
		fname = "minhnguy_dtai.txt";
		status = read_stdin(fname);
		if (!status)
			write(1, "map error\n", 10);
		else
			handle_file(fname);
	}
	else
	{
		itr = 0;
		while (++itr < argc)
		{
			handle_file(argv[itr]);
			if (itr != argc - 1)
				write(1, "\n", 1);
		}
	}
	return (0);
}
