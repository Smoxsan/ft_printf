CC := cc
CFLAGS := -Wall -Wextra -Werror
NAME := libftprintf.a 
SRC := 

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