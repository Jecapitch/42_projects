/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 00:10:50 by jpiscice          #+#    #+#             */
/*   Updated: 2025/05/31 21:14:07 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	create_thread(t_data *data, t_phi *philo, \
		pthread_t *thread, void *(*function)(void *))
{
	if (pthread_create(thread, NULL, function, (void *)philo))
	{
		write(2, THREAD_ERROR, sizeof(THREAD_ERROR));
		end_simulation(data);
		exit(EXIT_FAILURE);
	}
}

void	join_thread(t_data *data, pthread_t thread)
{
	if (pthread_join(thread, NULL))
	{
		write(2, JOIN_ERROR, sizeof(JOIN_ERROR));
		end_simulation(data);
		exit(EXIT_FAILURE);
	}
}

void	join_all_threads(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < (size_t)data->nbr)
	{
		join_thread(data, data->philo[i].thread);
		join_thread(data, data->philo[i].monitor);
		i++;
	}
}
