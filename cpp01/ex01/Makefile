CXX			:=	c++
FLAGS		:=	-Wall -Wextra -Werror -std=c++98
HEAD		:=	Zombie.hpp

SRCS		:=	main.cpp		\
				Zombie.cpp		\
				zombieHorde.cpp

OBJS		:=	$(SRCS:.cpp=.o)

TARGET		:=	horde.out

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