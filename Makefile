#NAME1 = push_swap
NAME2 = checker

LFT = libft/libft.a

SRC = src/swap.c src/push.c src/rotate.c src/rev_rotate.c src/ft_beauty.c \
	src/ps_list.c src/get_next_line.c src/if_sorted.c src/lst_free.c \
	src/checker.c $(LFT)

WWW = -Wall -Wextra -Werror

HEAD = includes/

#$(NAME1):
#	@make -C libft re && gcc -o $@ $(WWW) src/push_swap.c $(SRC) -I $(HEAD)
	
$(NAME2):
	@echo "(ﾉ◕ヮ◕)ﾉ*:・ﾟ✧ Compiling... Wait a sec."
	@make -C libft re && gcc -o $@ $(WWW) $(SRC) -I $(HEAD) -g
	@echo "(•̀ᴗ•́)و $(NAME2) generated!".

all: $(NAME2)

clean:
	@rm -f src/*.o
	@make -C libft/ fclean

fclean: clean
	@rm -rf $(NAME2)

re: fclean all
