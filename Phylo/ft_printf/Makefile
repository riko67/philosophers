SRC 	=	ft_putchar_fd.c\
		ft_putaddr.c\
		ft_putnbr_fd.c\
		ft_putnbrhexamaj.c\
		ft_putnbrhexamin.c\
		ft_putstr_fd.c\
		ft_unsignedputnbr_fd.c\
		ft_formatfiltre.c\
		ft_printf.c\



OBJS 	= ${SRC:.c=.o}

NAME	= libftprintf.a

FLAG 	= -Wall -Werror -Wextra 

CC 	= gcc ${FLAG}


all	: ${NAME}


${NAME}	: ${OBJS}
	  ar rc ${NAME} ${OBJS}
	  ranlib ${NAME}

clean	: 
	  rm -f ${OBJS}


fclean  : clean
	  rm -f ${NAME}

	
re	: fclean all


