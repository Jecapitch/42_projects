/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:46:57 by jpiscice          #+#    #+#             */
/*   Updated: 2025/05/29 18:28:28 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	destroy_forks(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < (size_t)data->nbr)
	{
		pthread_mutex_destroy(&data->fork_mutex[i]);
		i++;
	}
	return ;
}

void	free_table(t_data *data)
{
	if (data->philo)
	{
		free(data->philo);
		data->philo = NULL;
	}
	if (data->fork_mutex)
	{
		free(data->fork_mutex);
		data->fork_mutex = NULL;
	}
	return ;
}

void	end_simulation(t_data *data)
{
	destroy_forks(data);
	free_table(data);
	pthread_mutex_destroy(&data->glob_mutex);
}
