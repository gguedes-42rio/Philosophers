NAME	=	philo

SRC		=	$(addprefix func_philo/, ph_eat.c ph_sleep.c philosopher.c return_forks.c) \
			$(addprefix lst_philo/, add_philo.c clear_philo.c last_philo.c new_philo.c) \
			$(addprefix main/, init_global.c init_info.c main.c start_philo.c start_threads.c) \
			$(addprefix utils/, check_args.c check_eaten.c check_stop.c free_all.c ft_atol.c \
			get_ms.c print_action.c smart_sleep.c)

OBJ		=	$(SRC:.c=.o)

INCLUDE	=	-I.

CFLAGS	=	-Wall -Werror -Wextra -pthread

CC		=	cc

RM		=	rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(INCLUDE) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
