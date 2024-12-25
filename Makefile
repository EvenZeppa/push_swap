CC = gcc
C_FLAGS = -Wall -Wextra -Werror
INCLUDES = -Iinclude
PUSH_SWAP_SRCS = main.c elem.c stack.c metric.c operation.c
PUSH_SWAP_TARGET = push_swap
CHECKER_SRCS = checker/checker.c checker/get_next_line.c checker/get_next_line_utils.c
CHECKER_TARGET = checker1

all: $(PUSH_SWAP_TARGET)

$(PUSH_SWAP_TARGET):
	$(CC) -g $(C_FLAGS) $(INCLUDES) $(PUSH_SWAP_SRCS) libft.a -o $(PUSH_SWAP_TARGET)

clean:
	rm -f $(PUSH_SWAP_TARGET) $(CHECKER_TARGET)

re: clean all

bonus: $(CHECKER_TARGET)

$(CHECKER_TARGET):
	$(CC) $(C_FLAGS) $(INCLUDES) $(CHECKER_SRCS) libft.a -o $(CHECKER_TARGET)