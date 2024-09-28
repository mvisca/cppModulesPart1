COMP		:=	c++
FLAFS		:=	-Wall -Wextra -Werror -std=c++98
HEADS		:=	Zombie.hpp

SRCS		:=	main.cpp		\
				Zombie.hpp		\
				Zombie.cpp		\
				newZombie.cpp	\
				randomChump.cpp

OBJS		:=	$(SRCS:.cpp=.o)

TARGET		:=	brainz.out

all: $(TARGET)

$(TARGET): $(OBJS) Makefile
	$(COMP) $(FLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp $(HEAD)
	$(COMP) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

fclean: clean
	rm -f $(TARGET)

re: fclean all

-PHONY: all clean re