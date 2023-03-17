/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 02:31:10 by gguedes           #+#    #+#             */
/*   Updated: 2023/03/17 02:31:21 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start_threads(t_philo *philo, int philosophers)
{
	int			i;
	pthread_t	*ph;

	ph = malloc(sizeof(pthread_t) * (philosophers));
	i = -1;
	while (++i < philosophers)
	{
		pthread_create(&ph[i], NULL, &philosopher, (void *)philo);
		philo = philo->next;
	}
	i = -1;
	while (++i < philosophers)
		pthread_join(ph[i], NULL);
	free(ph);
	return (0);
}
