/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_forks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 02:15:35 by gguedes           #+#    #+#             */
/*   Updated: 2023/03/17 02:15:51 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	return_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex_fork);
	philo->fork++;
	pthread_mutex_unlock(&philo->mutex_fork);
	pthread_mutex_lock(&philo->next->mutex_fork);
	philo->next->fork++;
	pthread_mutex_unlock(&philo->next->mutex_fork);
}
