CXX			:=	c++

FLAGS		:=	-Wall -Wextra -Werror -std=c++98 -MMD

SRCS		:=	main.cpp		\
				Zombie.cpp		\
				newZombie.cpp	\
				randomChump.cpp

OBJS		:=	$(SRCS:.cpp=.o)

DEPS		:=	$(OBJS:.o=.d)

TARGET		:=	brainz

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(FLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp Makefile
	$(CXX) $(FLAGS) -c $< -o $@
-include $(DEPS)

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re