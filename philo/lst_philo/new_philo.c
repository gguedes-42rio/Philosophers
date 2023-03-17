/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 01:20:38 by gguedes           #+#    #+#             */
/*   Updated: 2023/03/17 02:36:11 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*new_philo(t_info *info, t_global *global, int id)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	philo->id = id;
	philo->fork = 1;
	philo->eaten = 0;
	philo->death = 0;
	philo->info = *info;
	philo->global = global;
	pthread_mutex_init(&philo->mutex_fork, NULL);
	philo->next = NULL;
	return (philo);
}
