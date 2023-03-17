NAME	=	philo_bonus

SRC		=	$(addprefix func_philo/, ph_eat.c philosopher.c vulture.c) \
			$(addprefix main/, close_sem.c main.c open_sem.c start_philo.c start_processes.c) \
			$(addprefix utils/, check_args.c check_exit.c ft_atol.c get_ms.c kill_all.c print_action.c)

OBJ		=	$(SRC:.c=.o)

INCLUDE	=	-I.

CFLAGS	=	-Wall -Werror -Wextra -pthread

CC		=	cc

RM		=	rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS )$(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(INCLUDE) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
