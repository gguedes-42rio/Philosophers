/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_sem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:26:24 by gguedes           #+#    #+#             */
/*   Updated: 2023/03/17 15:26:30 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	close_sem(t_philo *philo)
{
	sem_close(philo->sem_fork);
	sem_close(philo->sem_print);
	sem_unlink("/sem_fork");
	sem_unlink("/sem_print");
}
