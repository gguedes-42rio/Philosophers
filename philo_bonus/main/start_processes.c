/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_processes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:13:03 by gguedes           #+#    #+#             */
/*   Updated: 2023/03/17 15:46:30 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start_processes(t_philo *philo, int philosophers)
{
	int	*pid;

	pid = malloc(sizeof(int) * (philosophers));
	while (philo->id <= philosophers)
	{
		pid[philo->id - 1] = fork();
		if (pid[philo->id - 1] == 0)
		{
			free(pid);
			return (philosopher(philo));
		}
		philo->id++;
	}
	if (check_exit(philosophers))
		kill_all(pid, philosophers);
	free(pid);
	return (0);
}
