CC := cc
CFLAGS := -Wall -Wextra -Werror
NAME := libftprintf.a 
SRC := ft_print.c ft_printf_c.c ft_printf_d.c  ft_printf_hexlower.c  ft_printf_hexupper.c  ft_printf_i.c  ft_printf_p.c  ft_printf_per.c  ft_printf_s.c  ft_printf_u.c

OBJEKTS := $(SRC:.c=.o)

all:$(NAME)

$(NAME):$(OBJEKTS)
	ar rcs $@ $^
%.o: %.c
	$(CC) -c $(CFLAGS) $^ -o $@
clean:
	rm -f $(OBJEKTS)

fclean:clean
	rm -f $(NAME)
re:fclean all
.PHONY: clean fclean re