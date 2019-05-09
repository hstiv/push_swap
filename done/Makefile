NAME1 = push_swap
NAME2 = checker

LFT = libft/libft.a

SRC = src/swap.c src/push.c src/rotate.c src/rev_rotate.c src/ft_beauty.c \
	src/ps_list.c src/get_next_line.c src/if_sorted.c src/lst_free.c \
	src/checker.c src/numgive.c src/minmax.c src/recorder.c src/colors.c $(LFT) \
	src/valid_arg/valid_arg.c

SRC1 = src/swap.c src/push.c src/rotate.c src/rev_rotate.c src/ft_beauty.c \
	src/ps_list.c src/get_next_line.c src/if_sorted.c src/lst_free.c \
	src/push_swap.c src/minmax.c src/numgive.c src/operations.c $(LFT) \
	src/tools.c src/recorder.c src/colors.c src/valid_arg/valid_arg.c

WWW = -Wall -Wextra -Werror

HEAD = includes/

all: $(NAME1) $(NAME2)

$(NAME1):
	@echo "(ﾉ◕ヮ◕)ﾉ*:・ﾟ✧ Push_swap is compiling... Wait a sec."
	@make -C libft re && gcc $(WWW) -g -o $@ $(SRC1) -I $(HEAD)
	@rm -rf *.dSYM
	@echo "(•̀ᴗ•́)و $@ generated!".
	
$(NAME2):
	@echo "(ﾉ◕ヮ◕)ﾉ*:・ﾟ✧ Checker is compiling... Wait a sec."
	@make -C libft re && gcc $(WWW) -g -o $@ $(SRC) -I $(HEAD)
	@rm -rf *.dSYM
	@echo "(•̀ᴗ•́)و $(NAME2) generated!".

clean:
	@rm -f src/*.o
	@make -C libft/ fclean

fclean: clean
	@rm -rf $(NAME1) $(NAME2)

re: fclean all
