C++       	:= c++
CFLAGS 	 	:= -std=c++20 -Wall -Wextra -Werror
GDBFLAGS 	:= -ggdb

NAME     	:= megaphone
SRC      	:= megaphone.cpp \

INCLUDES 	:= -Iinclude
OBJ      	:= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(C++) $(OBJ) -o $@
	@clear
	@echo "✅ Build $(NAME) successfully!"

%.o: %.cpp 
	@$(C++) $(CFLAGS) $(INCLUDES) -c $< -o $@

gdb: CFLAGS += $(GDBFLAGS)
gdb: re
	@echo "Build with GDB symbols ready"

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.SECONDARY: $(OBJ)
.PHONY: all clean fclean re
