##
## EPITECH PROJECT, 2024
## makefile
## File description:
## task 01
##

# FILES
SRC=  	src/main.c \
		src/simulation/simulation_main.c \
		src/simulation/window.c \
		src/simulation/fps.c \
		src/lib/my_str_to_word_array.c \
		src/lib/my_atof.c \
		src/lib/concat.c \
		src/lib/strcmp.c \
		src/list/init_planes.c \
		src/list/error_handling.c \
		src/list/init_towers.c \
		src/list/free.c \
		src/list/linked_list.c \
		src/calculations/tower_range.c \
		src/calculations/update_planes.c \
		src/calculations/collisions_main.c \
		src/calculations/collisions.c \

# COLORS
RED=\033[31m
GREEN=\033[32m
WHITE=\033[37m
BOLD=\033[1m
RESET=\033[0m

# VARIABLES
OBJ =	$(SRC:.c=.o)
FLAGS = -lm -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio
CC = gcc
NAME = my_radar

# PRINT COMPILATION
%.o: %.c
	@echo "$(GREEN)$(BOLD)[COMPILING]:\t$(RESET)$(GREEN)$<$(RESET)"
	@$(CC) $(FLAGS) -c $< -o $@

# PRINT AND THEN COMPILE
all: pre-compile $(NAME)

# PRINT INFO
pre-compile:
	@echo "$(WHITE)$(BOLD)\t$(WHITE)[COMPILATION...]$(RESET)"

# COMPILATION
$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(FLAGS)
	@echo "$(WHITE)$(BOLD)\t[COMPILED SUCCESSFULLY]"
	@echo "[READY]:$(RESET)$(WHITE)\t$(NAME)$(RESET)"


# CLEAN OBJECT FILES
clean:
	@echo "$(WHITE)$(BOLD)\t[CLEANING OBJ...]$(RESET)"
	@for file in $(OBJ); do \
		if [ -f "$$file" ]; then \
			echo "$(RED)$(BOLD)[CLEAN]:\t$(RESET)$(RED)$$file$(RESET)"; \
			rm -f "$$file"; \
		fi; \
	done

# CLEAN EXEC / LIB
fclean:
	@echo "$(WHITE)$(BOLD)\t[CLEANING EXEC/LIB...]"
	@echo "$(RED)[CLEAN]:\t$(RESET)$(RED)$(NAME)$(RESET)"
	@rm -f $(NAME)
	@$(MAKE) clean -s

# CLEAN EVERYTHING AND RE-COMPILE
re: fclean all
