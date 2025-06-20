/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 22:32:25 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/04 00:12:15 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	check_argc(int argc)
{
	if (argc != 5 && argc != 6)
	{
		write(2, ARGC_ERROR, sizeof(ARGC_ERROR));
		exit(EXIT_SUCCESS);
	}
	return ;
}

void	parse(char **argv, t_data *data)
{
	data->nbr = ft_atoi_natural(argv[1]);
	data->time_to_die = ft_atoi_natural(argv[2]);
	data->time_to_eat = ft_atoi_natural(argv[3]);
	data->time_to_sleep = ft_atoi_natural(argv[4]);
	data->nbr_meals = ft_atoi_natural(argv[5]);
	if (data->nbr < 1 || data->time_to_die < 1 || data->time_to_eat < 1 \
		|| data->time_to_sleep < 1 || (argv[5] && data->nbr_meals < 1))
	{
		write(2, ARG_ERROR, sizeof(ARG_ERROR));
		exit(EXIT_FAILURE);
	}
	return ;
}
