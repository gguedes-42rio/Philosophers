/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 20:28:25 by gguedes           #+#    #+#             */
/*   Updated: 2022/11/02 20:28:25 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philosopher(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	philo->start = get_ms();
	philo->death = philo->start + philo->info.time_to_die;
	if (philo->id % 2 == 0)
		usleep(EVEN_START_DELAY);
	while (1)
	{
		print_action("%li %i is thinking\n", philo);
		if (ph_eat(philo))
			return (NULL);
		return_forks(philo);
		if (check_eaten(philo))
			return (NULL);
		if (ph_sleep(philo))
			return (NULL);
	}
	return (NULL);
}
