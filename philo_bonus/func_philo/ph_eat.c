/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:38:24 by gguedes           #+#    #+#             */
/*   Updated: 2023/03/17 15:38:32 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ph_eat(t_philo *philo)
{
	sem_wait(philo->sem_fork);
	print_action("%li %i has taken a fork\n", philo);
	sem_wait(philo->sem_fork);
	print_action("%li %i has taken a fork\n", philo);
	print_action("%li %i is eating\n", philo);
	pthread_mutex_lock(&philo->mutex_death);
	philo->death = get_ms() + philo->time_to_die;
	pthread_mutex_unlock(&philo->mutex_death);
	philo->eaten++;
	usleep(philo->time_to_eat * 1000);
	sem_post(philo->sem_fork);
	sem_post(philo->sem_fork);
}
