/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 21:49:13 by gguedes           #+#    #+#             */
/*   Updated: 2023/03/17 15:28:28 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	int		philosophers;
	t_philo	philo;

	if (check_args(argc - 1, &argv[1]))
		return (write(2, ARG_ERROR, 164));
	if (start_philo(&philo, &philosophers, &argv[1]))
		return (write(2, ARG_ERROR, 164));
	open_sem(&philo, philosophers);
	if (start_processes(&philo, philosophers))
		return (0);
	close_sem(&philo);
	return (0);
}
