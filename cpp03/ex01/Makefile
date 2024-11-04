CXX			:=	c++

CXXFLAGS	:=	-Wall -Wextra -Werror -std=c++98 -MMD

SRCS		:=	main.cpp		\
				ClapTrap.cpp	\
				ScavTrap.cpp

OBJS		:=	$(SRCS:.cpp=.o)

DEPS		:=	$(OBJS:.o=.d)

TARGET		:=	scavtrap

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp Makefile
	$(CXX) $(CXXFLAGS) -c $< -o $@
-include $(DEPS)

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re