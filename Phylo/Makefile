SRC 	= 		init.c \
			philo2.c \
			realrealmain.c \
			utils.c \
			ft_atoi.c 

		
LIB 	= -I ft_printf ft_printf/libftprintf.a

OBJS 	= $(SRC:.c=.o)

NAME	= philo

FLAGS 	= -Wall -Werror -Wextra -g3

CC 		= gcc

.c.o:
	$(CC) $(FLAGS) -I ft_printf -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	 $(MAKE) -C ft_printf 
	 $(CC) $(FLAGS) $(LIB) $(OBJS) -o $(NAME)

debug: $(OBJS)
	$(MAKE) -C ft_printf
	$(CC) $(FLAGS) $(LIB) $(OBJS) -fsanitize=address -o $(NAME)

clean: 
	$(MAKE) -C ft_printf clean
	  @rm -f $(OBJS)


fclean: clean
	$(MAKE) -C ft_printf clean
	  @rm -f $(NAME)


re: fclean all

.PHONY: all clean fclean re
