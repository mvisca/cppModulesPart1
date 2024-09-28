COMP		:=	c++
FLAFS		:=	-Wall -Wextra -Werror -std=c++98

SRCS		:=	main.cpp 				\
				AuxiliarFunctions.cpp	\
				Contact.cpp				\
				Interface.cpp			\
				PhoneBook.cpp

OBJS		:=	$(SRCS:.cpp=.o)

TARGET		:=	phoneBook.out

all: $(TARGET)

$(TARGET): $(OBJS) Makefile
	$(COMP) $(FLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp Contact.hpp PhoneBook.hpp GlobalHeaders.hpp
	$(COMP) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

fclean: clean
	rm -f $(TARGET)

re: fclean all

-PHONY: all clean re