COMP		:=	c++
FLAFS		:=	-Wall -Wextra -Werror -std=c++98

SRCS		:=	megaphone.cpp

OBJS		:=	$(SRCS:.cpp=.o)

TARGET		:=	megaphone.out

all: $(TARGET)

$(TARGET): $(OBJS) Makefile
	$(COMP) $(FLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(COMP) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

fclean: clean
	rm -f $(TARGET)

re: fclean all

-PHONY: all clean re