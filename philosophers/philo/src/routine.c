/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 22:24:45 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/04 00:38:28 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	thinking(t_data *data, t_phi *philo)
{
	size_t	time;

	pthread_mutex_lock(&data->glob_mutex);
	time = get_time_ms();
	if (!data->end_sim)
		print_message(data, time, philo->id, "is thinking");
	pthread_mutex_unlock(&data->glob_mutex);
	return ;
}

void	sleeping(t_data *data, t_phi *philo)
{
	size_t	start;

	pthread_mutex_lock(&data->glob_mutex);
	if (data->end_sim)
		return ((void)pthread_mutex_unlock(&data->glob_mutex));
	philo->state = WAIT;
	start = get_time_ms();
	print_message(data, start, philo->id, "is sleeping");
	pthread_mutex_unlock(&data->glob_mutex);
	while (timediff(start, get_time_ms()) < data->time_to_sleep)
		usleep(100);
	return ;
}

void	take_fork(t_data *data, t_phi *philo, pthread_mutex_t *fork)
{
	size_t	time;

	pthread_mutex_lock(fork);
	pthread_mutex_lock(&data->glob_mutex);
	time = get_time_ms();
	if (!data->end_sim)
		print_message(data, time, philo->id, "has taken a fork");
	pthread_mutex_unlock(&data->glob_mutex);
	return ;
}

void	eating(t_data *data, t_phi *philo)
{
	pthread_mutex_lock(&data->glob_mutex);
	philo->state = EAT;
	if (data->end_sim)
		return ((void)pthread_mutex_unlock(philo->fork), \
				(void)pthread_mutex_unlock(philo->spoon), \
				(void)pthread_mutex_unlock(&data->glob_mutex));
	philo->meal_count++;
	data->philo_done_eating += (data->nbr_meals > 0 \
								&& philo->meal_count == data->nbr_meals);
	philo->last_meal = get_time_ms();
	print_message(data, philo->last_meal, philo->id, "is eating");
	pthread_mutex_unlock(&data->glob_mutex);
	while (timediff(philo->last_meal, get_time_ms()) < data->time_to_eat)
		usleep(100);
	pthread_mutex_unlock(philo->fork);
	pthread_mutex_unlock(philo->spoon);
	return ;
}

void	*routine(void *philo)
{
	t_data	*data;
	t_phi	*phi;

	phi = (t_phi *)philo;
	data = phi->data;
	wait_start(data);
	pthread_mutex_lock(&data->glob_mutex);
	phi->last_meal = data->start_time;
	phi->state = WAIT;
	pthread_mutex_unlock(&data->glob_mutex);
	while (1)
	{
		pthread_mutex_lock(&data->glob_mutex);
		if (data->end_sim)
			return (pthread_mutex_unlock(&data->glob_mutex), philo);
		pthread_mutex_unlock(&data->glob_mutex);
		take_fork(data, phi, phi->fork);
		if (data->nbr == 1)
			return (pthread_mutex_unlock(phi->fork), philo);
		take_fork(data, phi, phi->spoon);
		eating(data, phi);
		sleeping(data, phi);
		thinking(data, phi);
	}
	return (philo);
}
