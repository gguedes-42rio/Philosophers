/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_sem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:11:04 by gguedes           #+#    #+#             */
/*   Updated: 2023/03/17 15:26:22 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	open_sem(t_philo *philo, int philosophers)
{
	sem_unlink("/sem_fork");
	sem_unlink("/sem_print");
	philo->sem_fork = sem_open("/sem_fork", O_CREAT | O_RDWR, 0777, philosophers);
	philo->sem_print = sem_open("/sem_print", O_CREAT | O_RDWR, 0777, 1);
}
