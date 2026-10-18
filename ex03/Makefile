# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Jpflegha <jpflegha@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/28 15:11:25 by jenne             #+#    #+#              #
#    Updated: 2026/06/03 17:13:16 by Jpflegha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Bureaucrat03
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
SRC = main.cpp Bureaucrat.cpp AForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp ShrubberyCreationForm.cpp Inter.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all re clean fclean