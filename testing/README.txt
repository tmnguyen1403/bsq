# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    README.txt                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dtai <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/28 18:28:18 by dtai              #+#    #+#              #
#    Updated: 2019/08/28 18:41:04 by dtai             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CORNER CASES WE'RE SURE OF:

-if there are a bunch of zeroes before the # of rows in the first line
-the number of rows is not equal to the number of rows given
-the number of cols in any row is not equal to the first col
-make sure that if a character that's an any, obstacle, or fill is not considered to be a digit in the # of rows
-if there's a character inside the board that's not an any or obstacle char
-not an integer to represent the number of rows in the first line
-there's a line break at the end of each line
-a 0 row board is invalid
-num of rows is larger than max int

CORNER CASES UNSURE OF:

-is a board with the same char for any and fill okay
-is a board with the same char for obstacle and fill okay
