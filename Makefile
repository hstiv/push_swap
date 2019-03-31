#NAME1 = push_swap
NAME2 = checker

SRC = src/swap.c src/push.c src/rotate.c src/rev_rotate.c src/push_swap.c src/checker.c \
	src/ps_list.c src/tools1.c $(LFT) src/get_next_line.c

LFT = libft/libft.a

WWW = -Wall -Wextra -Werror

HEAD = libft/

#$(NAME1):
#	@make -C libft re && gcc -o $@ $(WWW) $(SRC) -I $(HEAD)
	
$(NAME2):
	@make -C libft re && gcc -o $@ $(WWW) $(SRC) -I $(HEAD)

all: $(NAME2)

clean:
	@rm -f src/*.o
	@make -C libft fclean

fclean: clean
	@rm -rf $(NAME1) $(NAME2)

re: fclean all
