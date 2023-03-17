/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 02:02:29 by gguedes           #+#    #+#             */
/*   Updated: 2023/03/17 12:07:42 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	smart_sleep(long timer, t_philo *philo)
{
	long	end;

	end = get_ms() + timer;
	while (end > get_ms())
	{
		if (check_stop(philo))
			return (1);
		usleep(SMART_SLEEP_DELAY);
	}
	return (0);
}
