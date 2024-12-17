CC = gcc
C_FLAGS = -Wall -Wextra -Werror
INCLUDES = -Iinclude
CHECKER_SRCS = checker.c get_next_line.c get_next_line_utils.c
CHECKER_TARGET = checker

checker :
	$(CC) $(C_FLAGS) $(INCLUDES) $(CHECKER_SRCS) libft.a -o $(CHECKER_TARGET)