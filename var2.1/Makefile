NAME1 = push_swap
NAME2 = checker

LFT = libft/libft.a

SRC = src/swap.c src/push.c src/rotate.c src/rev_rotate.c src/ft_beauty.c \
	src/ps_list.c src/get_next_line.c src/if_sorted.c src/lst_free.c \
	src/checker.c src/numgive.c src/minmax.c $(LFT)

SRC1 = src/swap.c src/push.c src/rotate.c src/rev_rotate.c src/ft_beauty.c \
	src/ps_list.c src/get_next_line.c src/if_sorted.c src/lst_free.c \
	src/push_swap.c src/minmax.c src/numgive.c src/operations.c $(LFT) \
	src/tools.c

WWW = -Wall -Wextra -Werror

HEAD = includes/

$(NAME1):
	@echo "(ﾉ◕ヮ◕)ﾉ*:・ﾟ✧ Compiling... Wait a sec."
	@make -C libft re && gcc -o $@ $(SRC1) -I $(HEAD)
	
$(NAME2):
	@make -C libft re && gcc -o $@ $(SRC) -I $(HEAD)
	@echo "(•̀ᴗ•́)و $(NAME2) generated!".

all: $(NAME1) $(NAME2)

clean:
	@rm -f src/*.o
	@make -C libft/ fclean

fclean: clean
	@rm -rf $(NAME1) $(NAME2)

re: fclean all
