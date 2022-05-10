NAME		= philo

SRCS		= $(wildcard ./src/*.c)

OBJS		= $(patsubst %.c, %.o, $(SRCS))

CC			= cc

CFLAGS		=-Wall -Wextra -Werror

RM			= rm -rf


%.o:		%.c philosophers.h
			@$(CC) $(CFLAGS) -o $@ -c $<

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
			@echo "Compilation complete"
clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME)
			@echo "Cleared"
re:			fclean all

.PHONY:		all clean fclean re