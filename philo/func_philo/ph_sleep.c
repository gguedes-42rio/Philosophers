/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 02:14:16 by gguedes           #+#    #+#             */
/*   Updated: 2023/03/17 02:14:37 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ph_sleep(t_philo *philo)
{
	print_action("%li %i is sleeping\n", philo);
	return (smart_sleep(philo->info.time_to_sleep, philo));
}
