/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:59:00 by gguedes           #+#    #+#             */
/*   Updated: 2023/03/17 01:21:59 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	validate_str(char *str)
{
	if (!(ft_isdigit(*str) || *str == '+'))
		return (1);
	while (*++str)
	{
		if (!ft_isdigit(*str))
			return (1);
	}
	return (0);
}

int	check_args(int argc, char **argv)
{
	if (argc < 4 || argc > 5)
		return (1);
	while (argc--)
	{
		if (validate_str(argv[argc]))
			return (1);
	}
	return (0);
}
