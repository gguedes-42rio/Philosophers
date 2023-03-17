/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 02:02:07 by gguedes           #+#    #+#             */
/*   Updated: 2023/03/17 12:04:56 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(char *str, t_philo *philo)
{
	if (check_stop(philo))
		return ;
	pthread_mutex_lock(&philo->global->mutex_print);
	printf(str, get_ms() - philo->start, philo->id);
	pthread_mutex_unlock(&philo->global->mutex_print);
}
