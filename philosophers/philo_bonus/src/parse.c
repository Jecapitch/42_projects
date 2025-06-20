/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 22:32:25 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/06 04:47:56 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

int	check_argc(int argc)
{
	if (argc != 5 && argc != 6)
		return (write(2, ARGC_ERROR, ft_strlen(ARGC_ERROR)), -1);
	return (0);
}

int	parse(char **argv, t_data *data)
{
	data->nbr = ft_atoi_natural(argv[1]);
	data->time_to_die = ft_atoi_natural(argv[2]);
	data->time_to_eat = ft_atoi_natural(argv[3]);
	data->time_to_sleep = ft_atoi_natural(argv[4]);
	data->nbr_meals = ft_atoi_natural(argv[5]);
	if (data->nbr < 1 || data->nbr > 200 \
		|| data->time_to_die < 1 \
		|| data->time_to_eat < 1 \
		|| data->time_to_sleep < 1 \
		|| (argv[5] && data->nbr_meals < 1))
		return (print_error(data, ARG_ERROR), -1);
	return (0);
}
