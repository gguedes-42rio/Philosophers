/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 01:32:11 by gguedes           #+#    #+#             */
/*   Updated: 2023/03/17 12:04:42 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*start_philo(t_info *info, t_global *global, int philosophers)
{
	int		i;
	t_philo	*philo;

	philo = NULL;
	i = -1;
	while (++i < philosophers)
		add_philo(&philo, new_philo(info, global, i + 1));
	last_philo(philo)->next = philo;
	return (philo);
}
