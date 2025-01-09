CXX			:=	c++

FLAGS		:=	-Wall -Wextra -Werror -std=c++98 -MMD

SRCS		:=	main.cpp

OBJS		:=	$(SRCS:.cpp=.o)

DEPS		:=	$(OBJS:.o=.d)

TESTFILE	:=	test.txt

REPLACEFILE	:=	$(TESTFILE).replace

TARGET		:=	replace

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(FLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp Makefile
	$(CXX) $(FLAGS) -c $< -o $@
-include $(DEPS)

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(TARGET) $(TESTFILE) $(REPLACEFILE)

re: fclean all

# Opcional para crear archivo de prueba
test: all
	@echo "Este es un archivo de prueba" > $(TESTFILE)
	@echo "Archivo de prueba 'test.txt' creado con éxito."

.PHONY: all clean fclean re test