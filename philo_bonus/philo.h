/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 21:47:20 by gguedes           #+#    #+#             */
/*   Updated: 2023/03/17 15:46:57 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <fcntl.h>
# include <semaphore.h>
# include <signal.h>
# include <sys/wait.h>

# define ARG_ERROR "Usage: ./philo_bonus <number_of_philosophers> <time_to_die> \
<time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]\n\
All values must be positive numbers\n"
# define EVEN_START_DELAY 100

typedef struct s_philo {
	int				id;
	int				eaten;
	int				must_eat;
	long			start;
	long			death;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	sem_t			*sem_fork;
	sem_t			*sem_print;
	pthread_mutex_t	mutex_death;
}	t_philo;

// func_philo
void	ph_eat(t_philo *philo);
int		philosopher(t_philo *philo);
void	*vulture_aid(void *ptr);

// main
void	close_sem(t_philo *philo);
void	open_sem(t_philo *philo, int philosophers);
int		start_philo(t_philo *philo, int *philosophers, char **argv);
int		start_processes(t_philo *philo, int philosophers);

// utils
int		check_args(int argc, char **argv);
int		check_exit(int philosophers);
long	ft_atol(char const *str);
long	get_ms(void);
void	kill_all(int *pid, int philosophers);
void	print_action(char *str, t_philo *philo);

#endif