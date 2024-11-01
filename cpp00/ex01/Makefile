CXX			:=	c++
FLAGS		:=	-Wall -Wextra -Werror -std=c++98

SRCS		:=	main.cpp 				\
				AuxiliarFunctions.cpp	\
				Contact.cpp				\
				Interface.cpp			\
				PhoneBook.cpp

OBJS		:=	$(SRCS:.cpp=.o)

TARGET		:=	phoneBook

all: $(TARGET)

$(TARGET): $(OBJS) Makefile
	$(CXX) $(FLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp Contact.hpp PhoneBook.hpp GlobalHeaders.hpp
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean re
