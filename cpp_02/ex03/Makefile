C++       	:= c++
CFLAGS 	 	:= -std=c++20 -Wall -Wextra -Werror

NAME     	:= fixedpoint_ex03
SRC      	:= main.cpp \
			   Fixed.cpp \
			   Point.cpp \
			   bsp.cpp \

OBJ_DIR   	:= .obj
OBJ       	:= $(SRC:%.cpp=$(OBJ_DIR)/%.o)

INCLUDES 	:= -Iinclude

all: $(NAME)

$(NAME): $(OBJ)
	@$(C++) $(OBJ) -o $@
	@echo "Build $(NAME) successfully!"

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	@$(C++) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.SECONDARY: $(OBJ)
.PHONY: all clean fclean re
