NAME = push_swap
BONUS_NAME = checker
LIBFT = libft.a
CC = gcc
RM = rm -rf
MKDIR = mkdir -p
FSAN = -fsanitize=address -g3
CFLAGS = -Wall -Wextra -Werror #${FSAN}

RED = \033[0;91m
GREEN = \033[92m
RESET = \033[0m

SRCS_FILES = push_swap.c \
	push_swap_ps.c \
    push_swap_rr.c \
    push_swap_rrr.c \
    push_swap_init.c \
    push_swap_util.c \
    push_swap_util2.c \
    push_swap_sort.c \
    push_swap_quick.c \
    push_swap_insert.c

BONUS_FILES_DIR = bonus/

BONUS_FILES = checker.c \
	checker_ps.c \
    checker_rr.c \
    checker_rrr.c \
	checker_init.c \
	checker_utils.c \
	checker_utils2.c \

SRCS_DIR = srcs/
LIBFT_DIR = libft
INC_DIR = inc
OBJS_DIR = objs/
BONUS_OBJS_DIR = bonus_objs/

OBJS = $(addprefix $(OBJS_DIR), $(SRCS_FILES:.c=.o))
BONUS_OBJS = $(addprefix $(BONUS_OBJS_DIR), $(BONUS_FILES:.c=.o))

LIBR = $(LIBFT_DIR)/libft.a

all: $(OBJS_DIR) libft $(NAME)

bonus: $(BONUS_OBJS_DIR) libft $(BONUS_NAME)
	@echo "$(GREEN)$(NAME) checker compiled!$(RESET)"

$(BONUS_NAME): $(BONUS_OBJS)
	@$(CC) $(CFLAGS) -L$(LIBFT_DIR) -l$(LIBFT:lib%.a=%) $(BONUS_OBJS) -o $(BONUS_NAME)

$(OBJS_DIR):
	@$(MKDIR) $(OBJS_DIR)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(BONUS_OBJS_DIR):
	@$(MKDIR) $(BONUS_OBJS_DIR)

$(BONUS_OBJS_DIR)%.o: $(BONUS_FILES_DIR)%.c
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -L$(LIBFT_DIR) -l$(LIBFT:lib%.a=%) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled!$(RESET)"

libft:
	@make -C $(LIBFT_DIR)

clean:
	@$(RM) $(OBJS_DIR) $(BONUS_OBJS_DIR)
	@make clean -C $(LIBFT_DIR)
	@echo "$(RED)$(NAME) objects cleaned!$(RESET)"

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@$(RM) $(NAME) $(BONUS_NAME)
	@echo "$(RED)$(NAME) cleaned!$(RESET)"

re: fclean all

.PHONY: all bonus libft clean fclean re
