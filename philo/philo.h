/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:51:38 by gguedes           #+#    #+#             */
/*   Updated: 2023/03/17 12:12:07 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>

# define ARG_ERROR "Usage: ./philo <number_of_philosophers> <time_to_die> \
<time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]\n\
All values must be positive numbers\n"
# define SMART_SLEEP_DELAY 500
# define EVEN_START_DELAY 100

typedef struct s_info {
	int		must_eat;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
}	t_info;

typedef struct s_global {
	int				stop;
	int				eaten;
	pthread_mutex_t	mutex_stop;
	pthread_mutex_t	mutex_eaten;
	pthread_mutex_t	mutex_print;
}	t_global;

typedef struct s_philo {
	int				id;
	int				fork;
	int				eaten;
	long			start;
	long			death;
	t_info			info;
	t_global		*global;
	struct s_philo	*next;
	pthread_mutex_t	mutex_fork;
}	t_philo;

// func_philo
int		ph_eat(t_philo *philo);
int		ph_sleep(t_philo *philo);
void	*philosopher(void *ptr);
void	return_forks(t_philo *philo);

// lst_philo
void	add_philo(t_philo **philo, t_philo *new);
void	clear_philo(t_philo *philo);
t_philo	*last_philo(t_philo *philo);
t_philo	*new_philo(t_info *info, t_global *global, int id);

// main
void	init_global(t_global *global, int philosophers);
int		init_info(t_info *info, int *philosophers, char **argv);
t_philo	*start_philo(t_info *info, t_global *global, int philosophers);
int		start_threads(t_philo *philo, int philosophers);

//utils
int		check_args(int argc, char **argv);
int		check_eaten(t_philo *philo);
int		check_stop(t_philo *philo);
void	free_all(t_global *global, t_philo *philo);
long	ft_atol(char const *str);
long	get_ms(void);
void	print_action(char *str, t_philo *philo);
int		smart_sleep(long timer, t_philo *philo);

#endif