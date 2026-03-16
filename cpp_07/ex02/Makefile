C++       	:= c++
CFLAGS 	 	:= -std=c++20 -Wall -Wextra -Werror -Wshadow

NAME     	:= array

SRC_DIR		:= src
INC_DIR		:= include
OBJ_DIR   	:= obj

SRC      	:= main.cpp \

SRCS       := $(addprefix $(SRC_DIR)/, $(SRC))
OBJ       	:= $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
INCLUDES 	:= -I$(INC_DIR)

all: $(NAME)

$(NAME): $(OBJ)
	@$(C++) $(OBJ) -o $@
	@echo "Build $(NAME) successfully!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
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
