/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 01:53:54 by gguedes           #+#    #+#             */
/*   Updated: 2023/03/17 02:39:59 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clear_philo(t_philo *philo)
{
	t_philo	*tmp;
	t_philo	*first;

	if (!philo)
		return ;
	first = philo;
	while (philo->next != first)
	{
		tmp = philo->next;
		pthread_mutex_destroy(&philo->mutex_fork);
		free(philo);
		philo = tmp;
	}
	pthread_mutex_destroy(&philo->mutex_fork);
	free(philo);
}
