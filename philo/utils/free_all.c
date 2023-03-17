/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 02:10:34 by gguedes           #+#    #+#             */
/*   Updated: 2023/03/17 02:12:52 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_global *global, t_philo *philo)
{
	pthread_mutex_destroy(&global->mutex_stop);
	pthread_mutex_destroy(&global->mutex_eaten);
	pthread_mutex_destroy(&global->mutex_print);
	clear_philo(philo);
}
