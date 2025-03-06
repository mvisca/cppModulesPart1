# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/13 09:27:47 by mvisca            #+#    #+#              #
#    Updated: 2025/02/13 17:10:42 by mvisca           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX		:=	c++
CXXF	:=	-Wall -Wextra -Werror -std=c++98 -MMD
SRC		:=	main.cpp \
			Bureaucrat.cpp
OBJ 	:=	$(SRC:.cpp=.o)
DEP		:=	$(OBJ:.o=.d)
TARGET	:=	bureaucrat

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

%.o: %.cpp Makefile
	$(CXX) $(CXXLFLAGS) -c $< -o $@
-include $(DEP)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re