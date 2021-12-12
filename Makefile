SRCDIR = src/
OBJDIR = bin/
INCLUDE = include/

SRCS = ft_printf.c\
		write_buf.c\
		parse_flags.c\
		print_s.c\
		print_c.c\
		print_u.c\
		print_di.c\
		print_p.c\
		print_xX.c\
		print_percent.c

OBJS = $(addprefix $(OBJDIR), $(SRCS:.c=.o))

FTPATH = libft/
FTLIB = libft.a

AR = ar rc
CC = clang
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

INCPATH = -I$(FTPATH) -I$(INCLUDE)

all: $(NAME)

bonus: $(NAME)

libft:
	make -C $(FTPATH)
	cp $(FTPATH)$(FTLIB) $(NAME)

$(NAME): libft $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) -c $(CFLAGS) $(INCPATH) $< -o $@

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean ${NAME}

.PHONY: all libft clean fclean re
