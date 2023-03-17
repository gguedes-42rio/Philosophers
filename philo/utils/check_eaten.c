/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_eaten.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 02:21:37 by gguedes           #+#    #+#             */
/*   Updated: 2023/03/17 02:24:43 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_eaten(t_philo *philo)
{
	pthread_mutex_lock(&philo->global->mutex_eaten);
	if (philo->eaten == philo->info.must_eat)
	{
		philo->global->eaten--;
		if (philo->global->eaten == 0)
		{
			pthread_mutex_unlock(&philo->global->mutex_eaten);
			pthread_mutex_lock(&philo->global->mutex_stop);
			philo->global->stop++;
			pthread_mutex_unlock(&philo->global->mutex_stop);
		}
		else
			pthread_mutex_unlock(&philo->global->mutex_eaten);
		return (1);
	}
	pthread_mutex_unlock(&philo->global->mutex_eaten);
	return (0);
}
