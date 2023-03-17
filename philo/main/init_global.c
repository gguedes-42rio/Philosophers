/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_global.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 01:43:00 by gguedes           #+#    #+#             */
/*   Updated: 2023/03/17 11:35:47 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_global(t_global *global, int philosophers)
{
	global->eaten = philosophers;
	global->stop = 0;
	pthread_mutex_init(&global->mutex_stop, NULL);
	pthread_mutex_init(&global->mutex_eaten, NULL);
	pthread_mutex_init(&global->mutex_print, NULL);
}
