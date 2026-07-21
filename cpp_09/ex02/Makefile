C++       	:= c++
CFLAGS 	 	:= -std=c++20 -Wall -Wextra -Werror -O2 -g

NAME     	:= PmergeMe 

SRC_DIR		:= src
INC_DIR		:= include
OBJ_DIR   	:= obj

SRC      	:= main.cpp \
			   PmergeMe.cpp

SRCS       := $(addprefix $(SRC_DIR)/, $(SRC))
OBJ       	:= $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
INCLUDES 	:= -I$(INC_DIR)

all: $(NAME)

debug: CFLAGS += -DDEBUG
debug: re

$(NAME): $(OBJ)
	@$(C++) $(CFLAGS) $(OBJ) -o $@
	@echo "$(SWAP) Build $(NAME) successfully!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@$(C++) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

# Colors
RESET		= \033[0m
SWAP		= \033[7m

.SECONDARY: $(OBJ)
.PHONY: all clean fclean re debug
