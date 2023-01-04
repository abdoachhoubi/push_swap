SRC = ${addprefix algo_utils/, push.c reverse.c rotate.c swap.c} \
		${addprefix stack_utils/stack_utils, 1.c 2.c} \
		error.c push_swap.c

NAME = push_swap
CC = cc
INC = push_swap.h
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a

all: ${NAME}

${NAME}: ${PRINTF} ${LIBFT}
	@${CC} ${SRC} ${PRINTF} ${LIBFT} -I ${INC} -o push_swap
	@echo "push_swap is ready -_-"

${PRINTF}:
	@make -C ft_printf
	@echo "ft_printf is ready -_-"

${LIBFT}:
	@make -C libft
	@echo "libft is ready -_-"

clean:
	@make clean -C ft_printf
	@make clean -C libft
	@echo "Removed all object files"

fclean: clean
	@${RM} ${NAME}
	@make fclean -C ft_printf
	@make fclean -C libft
	@echo "Removed push_swap"
	@echo "Removed libftprintf.a"
	@echo "Removed libft.a"

re: fclean all