/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vulture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:19:55 by gguedes           #+#    #+#             */
/*   Updated: 2023/03/17 15:51:35 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*vulture_aid(void *ptr)
{
	t_philo	*philo;

	philo = ptr;
	while (1)
	{
		pthread_mutex_lock(&philo->mutex_death);
		if (philo->death <= get_ms())
		{
			pthread_mutex_unlock(&philo->mutex_death);
			sem_wait(philo->sem_print);
			printf("%li %i is dead\n", get_ms() - philo->start, philo->id);
			exit(1);
		}
		else
			pthread_mutex_unlock(&philo->mutex_death);
		usleep(500);
	}
	return (NULL);
}
