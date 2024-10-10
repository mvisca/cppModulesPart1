CXX			:=	c++
FLAGS		:=	-Wall -Wextra -Werror -std=c++98
HEAD		:=	Zombie.hpp

SRCS		:=	main.cpp

OBJS		:=	$(SRCS:.cpp=.o)

TARGET		:=	hiThisIsBrain.out

all: $(TARGET)

$(TARGET): $(OBJS) Makefile
	$(CXX) $(FLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp $(HEAD)
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean re