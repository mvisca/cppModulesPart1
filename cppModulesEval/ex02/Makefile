# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/13 09:27:47 by mvisca            #+#    #+#              #
#    Updated: 2025/02/16 00:31:00 by mvisca           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX		:=	c++
CXXF	:=	-Wall -Wextra -Werror -std=c++98 -MMD

SRC		:=	main.cpp 					\
			Bureaucrat.cpp				\
			AForm.cpp					\
			ShrubberyCreationForm.cpp	\
			RobotomyRequestForm.cpp		\
			PresidentialPardonForm.cpp

OBJ_DIR	:=	.obj
OBJ		:=	$(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRC))
DEP		:=	$(OBJ:.o=.d)

TARGET	:=	28B

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXF) -o $(TARGET) $(OBJ)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CXX) $(CXXF) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

-include $(DEP)

clean:
	rm -rf $(OBJ_DIR)
	rm -f *_shrubbery

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
