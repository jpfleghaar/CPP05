# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jenne <jpflegha@student.42heilbronn.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/28 15:11:25 by jenne             #+#    #+#              #
#    Updated: 2026/05/28 15:30:59 by jenne            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Bureacrat
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++17
SRC = main.cpp Bureacrat.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
fclean:
	rm -f $(NAME)
re: fclean all

.PHONY: all re clean fclean