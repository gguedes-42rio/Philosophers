/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 01:20:54 by gguedes           #+#    #+#             */
/*   Updated: 2023/03/17 02:45:20 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	add_philo(t_philo **philo, t_philo *new)
{
	if (!new)
		return ;
	if (!*philo)
		*philo = new;
	else
		last_philo(*philo)->next = new;
}
