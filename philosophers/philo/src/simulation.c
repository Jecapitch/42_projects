/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 00:10:50 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/04 00:37:08 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	launch_simulation(t_data *data)
{
	size_t	i;

	pthread_mutex_lock(&data->glob_mutex);
	i = 0;
	while (i < (size_t)data->nbr)
	{
		create_thread(data, &data->philo[i], &data->philo[i].thread, routine);
		create_thread(data, &data->philo[i], &data->philo[i].monitor, monitor);
		i++;
	}
	data->start_time = get_time_ms();
	data->start_sim = 1;
	pthread_mutex_unlock(&data->glob_mutex);
	return ;
}

void	wait_start(t_data *data)
{
	while (1)
	{
		pthread_mutex_lock(&data->glob_mutex);
		if (data->start_sim)
			break ;
		pthread_mutex_unlock(&data->glob_mutex);
		usleep(100);
	}
	pthread_mutex_unlock(&data->glob_mutex);
	return ;
}

void	*monitor(void *philo)
{
	t_phi	*phi;
	t_data	*data;
	size_t	time;

	phi = (t_phi *)philo;
	data = phi->data;
	wait_start(data);
	while (1)
	{
		pthread_mutex_lock(&data->glob_mutex);
		time = get_time_ms();
		if (phi->state == WAIT && !data->dead \
			&& timediff(phi->last_meal, time) > data->time_to_die)
			return (data->dead = phi->id, \
					print_message(data, time, data->dead, "died"), \
					data->end_sim = data->dead, \
					pthread_mutex_unlock(&data->glob_mutex), \
					philo);
		if (data->dead || data->philo_done_eating == data->nbr)
			return (data->end_sim = -1, \
					pthread_mutex_unlock(&data->glob_mutex), \
					philo);
		pthread_mutex_unlock(&data->glob_mutex);
		usleep(100);
	}
}
