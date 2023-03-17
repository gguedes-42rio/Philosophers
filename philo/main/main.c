/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:43:23 by gguedes           #+#    #+#             */
/*   Updated: 2023/03/17 11:36:12 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	int			philosophers;
	t_info		info;
	t_global	global;
	t_philo		*philo;

	if (check_args(argc - 1, &argv[1]))
		return (write(2, ARG_ERROR, 164));
	if (init_info(&info, &philosophers, argv + 1))
		return (write(2, ARG_ERROR, 164));
	init_global(&global, philosophers);
	philo = start_philo(&info, &global, philosophers);
	start_threads(philo, philosophers);
	free_all(&global, philo);
	return (0);
}
