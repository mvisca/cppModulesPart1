CXX			:=	c++
FLAGS		:=	-Wall -Wextra -Werror -std=c++98

SRCS		:=	megaphone.cpp

OBJS		:=	$(SRCS:.cpp=.o)

TARGET		:=	megaphone

all: $(TARGET)

$(TARGET): $(OBJS) Makefile
	$(CXX) $(FLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean re