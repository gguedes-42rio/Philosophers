/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:10:27 by gguedes           #+#    #+#             */
/*   Updated: 2023/03/17 02:46:37 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_info(t_info *info, int *philosophers, char **argv)
{
	*philosophers = ft_atol(argv[0]);
	if (*philosophers < 1)
		return (1);
	info->time_to_die = atol(argv[1]);
	if (info->time_to_die < 1)
		return (1);
	info->time_to_eat = atol(argv[2]);
	if (info->time_to_eat < 1)
		return (1);
	info->time_to_sleep = atol(argv[3]);
	if (info->time_to_sleep < 1)
		return (1);
	if (argv[4])
	{
		info->must_eat = atol(argv[4]);
		if (info->must_eat < 1)
			return (1);
	}
	else
		info->must_eat = -1;
	return (0);
}
