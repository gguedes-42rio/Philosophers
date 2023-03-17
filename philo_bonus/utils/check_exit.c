/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:44:30 by gguedes           #+#    #+#             */
/*   Updated: 2023/03/17 15:47:02 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_exit(int philosophers)
{
	int	i;
	int	status;

	i = 0;
	while (i < philosophers)
	{
		waitpid(0, &status, 0);
		if (WEXITSTATUS(status) == 1)
			return (1);
		i++;
	}
	return (0);
}
