NAME_C		= client
NAME_S		= server
NAME		= $(NAME_C) $(NAME_S)
CC			= cc
FLAGS		= -g -Wall -Werror -Wextra
RM			= rm -f

SRC_C		= client.c
OBJS_C		= $(SRC_C:.c=.o)
SRC_S		= server.c
OBJS_S		= $(SRC_S:.c=.o)

%.o: %.c
			$(CC) $(FLAGS) -c $< -o $@

all: 		library $(NAME)

server: 	$(OBJS_S) 
			$(CC) $(FLAGS) -o $(NAME_S) $(OBJS_S) libft/*.o ft_printf/*.o

client: 	$(OBJS_C) 
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

.PHONY: all clean fclean re libft ft_printf client server
