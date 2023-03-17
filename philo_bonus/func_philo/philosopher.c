/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:23:09 by gguedes           #+#    #+#             */
/*   Updated: 2023/03/17 15:51:47 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philosopher(t_philo *philo)
{
	pthread_t	vulture;

	pthread_mutex_init(&philo->mutex_death, NULL);
	philo->start = get_ms();
	philo->death = philo->start + philo->time_to_die;
	pthread_create(&vulture, NULL, &vulture_aid, (void *)philo);
	pthread_detach(vulture);
	if (philo->id % 2 == 0)
		usleep(EVEN_START_DELAY);
	while (1)
	{
		print_action("%li %i is thinking\n", philo);
		ph_eat(philo);
		if (philo->eaten == philo->must_eat)
			return (1);
		print_action("%li %i is sleeping\n", philo);
		usleep(philo->time_to_sleep * 1000);
	}
	return (0);
}
