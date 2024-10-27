CXX             :=      c++

FLAGS           :=      -Wall -Wextra -Werror -std=c++98

SRCS            :=      main.cpp Harl.cpp

OBJS            :=      $(SRCS:.cpp=.o)

TARGET          :=      harl.out

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(FLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp Harl.hpp
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re