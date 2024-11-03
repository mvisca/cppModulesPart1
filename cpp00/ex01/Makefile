CXX			:=	c++
FLAGS		:=	-Wall -Wextra -Werror -std=c++98

SRCS		:=	main.cpp 				\
				AuxiliarFunctions.cpp	\
				Contact.cpp				\
				Interface.cpp			\
				PhoneBook.cpp

HEADERS		:=	Contact.hpp 			\
				PhoneBook.hpp 			\
				GlobalHeader.hpp

OBJS		:=	$(SRCS:.cpp=.o)

DEPS 		:= $(OBJS:.o=.d)

TARGET		:=	phoneBook

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(FLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp $(HEADERS) Makefile
	$(CXX) $(FLAGS) -c $< -o $@
-include $(DEPS)

clean:
	rm -f $(OBJS) $(TARGET)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean
