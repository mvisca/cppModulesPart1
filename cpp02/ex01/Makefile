CXX             :=      c++

FLAGS           :=      -Wall -Wextra -Werror -std=c++98

SRCS            :=      main.cpp Fixed.cpp

OBJS            :=      $(SRCS:.cpp=.o)

TARGET          :=      fixed_point

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(FLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp Fixed.hpp
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
