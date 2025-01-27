CC = gcc
C_FLAGS = -Wall -Wextra -Werror
LIBFT_FOLDER = ft_lib
LIBFT = $(LIBFT_FOLDER)/lib/libft.a
SRCS = main.c init.c elem.c stack.c stack1.c stack2.c metric.c operation.c operation1.c operation2.c move.c solver.c int_tab.c
TARGET = push_swap

all: $(LIBFT) $(TARGET)

$(LIBFT):
	make -C $(LIBFT_FOLDER)

$(TARGET):
	$(CC) -g $(C_FLAGS) -I$(LIBFT_FOLDER)/include $(SRCS) $(LIBFT) -o $(TARGET)

clean:
	make -C $(LIBFT_FOLDER) clean
	rm -f $(TARGET)

fclean: clean
	make -C $(LIBFT_FOLDER) fclean

re: fclean all