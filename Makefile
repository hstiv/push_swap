NAME1 = push_swap

NAME2 = checker

SRC = src/swap.c src/push.c src/rotate.c src/rev_rotate.c src/push_swap.c src/checker.c $(LFT)

LFT = libft/libft.a

HEAD = /push_swap.h

WWW = -Wall -Wextra -Werror


$(NAME1):
	@make -C libft re && gcc -o $@ $(WWW) $(SRC) -I $(HEAD)
	
$(NAME2):
	@gcc -o $@ $(WWW) $(SRC) -I $(HEAD)

all: $(NAME1) $(NAME2)

clean:
	@rm -f src/*.o
	@make -C libft fclean

fclean:
	@rm -rf $(NAME1) $(NAME2)

re: fclean all
