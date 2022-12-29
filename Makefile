SRC = ${addprefix utils, 1.c 2.c 3.c} \
		${addprefix list_utils, 1.c 2.c} \
		push_swap.c

NAME = push_swap
CC = cc
INC = push_swap.h
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a

all: ${NAME}

${NAME}: ${PRINTF}
	@${CC} ${SRC} ${PRINTF} -I ${INC}
	@echo "push_swap is ready -_-"

${PRINTF}:
	@make -C ft_printf
	@echo "ft_printf is ready -_-"

clean:
	@make clean -C ft_printf
	@echo "Removed all object files"

fclean: clean
	@${RM} ${NAME}
	@make fclean -C ft_printf
	@echo "Removed push_swap"
	@echo "Removed ft_printf"

re: fclean all