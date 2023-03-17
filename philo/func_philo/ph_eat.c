/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 20:19:07 by gguedes           #+#    #+#             */
/*   Updated: 2022/11/02 20:19:07 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	safe_take(t_philo *philo, t_philo *ph_fork)
{
	pthread_mutex_lock(&ph_fork->mutex_fork);
	if (ph_fork->fork)
	{
		ph_fork->fork--;
		pthread_mutex_unlock(&ph_fork->mutex_fork);
		print_action("%li %i has taken a fork\n", philo);
		return (1);
	}
	else
		pthread_mutex_unlock(&ph_fork->mutex_fork);
	return (0);
}

static int	take_forks(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (check_stop(philo))
			return (1);
		i += safe_take(philo, philo);
		if (check_stop(philo))
			return (1);
		i += safe_take(philo, philo->next);
	}
	return (0);
}

int	ph_eat(t_philo *philo)
{
	if (take_forks(philo))
		return (1);
	print_action("%li %i is eating\n", philo);
	philo->death = get_ms() + philo->info.time_to_die;
	philo->eaten++;
	return (smart_sleep(philo->info.time_to_eat, philo));
}
