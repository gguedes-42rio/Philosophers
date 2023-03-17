/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 02:02:07 by gguedes           #+#    #+#             */
/*   Updated: 2023/03/17 15:47:26 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(char *str, t_philo *philo)
{
	sem_wait(philo->sem_print);
	printf(str, get_ms() - philo->start, philo->id);
	sem_post(philo->sem_print);
}
