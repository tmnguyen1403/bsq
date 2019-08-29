# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minhnguy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/26 14:32:46 by minhnguy          #+#    #+#              #
#    Updated: 2019/08/28 21:52:41 by minhnguy         ###   ########.fr        #
#    Updated: 2019/08/26 19:42:23 by dtai             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
FLAGS = -Wall -Wextra -Werror
INCLUDES = includes/
SRCS = srcs/main.c srcs/optimize.c srcs/helper_bsq.c srcs/valid.c \
	   srcs/small_bsq.c srcs/read_stdin.c srcs/obs.c
OBJECTS = main.o optimize.o helper_bsq.o valid.o small_bsq.o read_stdin.o \
		  obs.o

all: $(NAME)

$(NAME): $(OBJECTS)
	gcc $(FLAGS) $(OBJECTS) -o $(NAME) -I $(INCLUDES)

$(OBJECTS).o:
	gcc $(FLAGS) -c $(SRCS) -I $(INCLUDES)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
