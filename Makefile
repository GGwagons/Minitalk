NAME_C		= client
NAME_S		= server
CC			= cc
FLAGS		= -Wall -Werror -Wextra
RM			= rm -f

SRC_C		= client.c
OBJS_C		= $(SRC_C:.c=.o)
SRC_S		= server.c
OBJS_S		= $(SRC_S:.c=.o)

%.c: %.o
	$(CC) $(FLAGS) -c $< -o $@

all: 	client server

server: 	library $(OBJS_S) 
			$(CC) $(FLAGS) -o $(NAME_S) $(OBJS_S) libft/*.o ft_printf/*.o

client: 	library $(OBJS_C) 
			$(CC) $(FLAGS) -o $(NAME_C) $(OBJS_C) libft/*.o ft_printf/*.o

library:
			@ make -C libft/
			@ make -C ft_printf/
clean:		
			@ $(RM) $(OBJS_C) $(OBJS_S)
			@ make -C libft/ clean
			@ make -C ft_printf/ clean

fclean: 	clean
			@ $(RM) $(NAME_S) $(NAME_C)
			@ make -C libft/ fclean
			@ make -C ft_printf/ fclean

re: fclean all

.PHONY: all clean fclean re libft ft_printf/