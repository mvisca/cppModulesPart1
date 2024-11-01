CXX			:=	c++
FLAGS		:=	-Wall -Wextra -Werror -std=c++98
HEAD		:=

SRCS		:=	main.cpp

OBJS		:=	$(SRCS:.cpp=.o)

TARGET		:=	replace

all: $(TARGET)

$(TARGET): $(OBJS) Makefile
	$(CXX) $(FLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp $(HEAD)
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET) test.txt

fclean: clean
	rm -f $(TARGET)

re: fclean all

# Opcional para crear archivo de prueba
test: all
	@echo "Este es un archivo de prueba" > test.txt
	@echo "Archivo de prueba 'test.txt' creado con éxito."

.PHONY: all clean re test