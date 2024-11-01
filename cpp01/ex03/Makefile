CXX			:=	c++
FLAGS		:=	-Wall -Wextra -Werror -std=c++98
HEAD		:=	Weapon.hpp HumanA.hpp HumanB.hpp

SRCS		:=	main.cpp		\
				Weapon.cpp		\
				HumanA.cpp		\
				HumanB.cpp

OBJS		:=	$(SRCS:.cpp=.o)

TARGET		:=	unnecessaryViolence

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