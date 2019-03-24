NAME1 = push_swap

NAME2 = checker

SRC = swap.c push.c rotate.c rev_rotate.c push_swap.c checker.c $(LFT)

LFT = libft/libft.a

WWW = -Wall -Wextra -Werror

HEAD = libft/

$(NAME1):
	@make -C libft re && gcc -o $@ $(WWW) $(SRC) -I $(HEAD)
	
$(NAME2):
	@make -C libft re && gcc -o $@ $(WWW) $(SRC) -I $(HEAD)

all: $(NAME1) $(NAME2)

clean:
	@rm -f src/*.o
	@make -C libft fclean

fclean: clean
	@rm -rf $(NAME1) $(NAME2)

re: fclean all
