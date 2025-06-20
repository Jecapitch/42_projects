/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 22:24:45 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/20 07:32:23 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

int	thinking(t_data *data, t_phi *philo)
{
	sem_wait(data->glob_sem);
	if (philo->state == END)
		return (sem_post(data->glob_sem), 1);
	print_message(data, get_time_ms(), philo->id, "is thinking");
	sem_post(data->glob_sem);
	return (0);
}

int	sleeping(t_data *data, t_phi *philo)
{
	size_t	start;

	sem_wait(data->glob_sem);
	if (philo->state == END)
		return (sem_post(data->glob_sem), 1);
	start = get_time_ms();
	print_message(data, start, philo->id, "is sleeping");
	philo->state = WAIT;
	sem_post(data->glob_sem);
	while (timediff(start, get_time_ms()) < data->time_to_sleep)
	{
		sem_wait(data->glob_sem);
		if (philo->state == END)
			return (sem_post(data->glob_sem), 1);
		sem_post(data->glob_sem);
	}
	return (0);
}

int	take_forks(t_data *data, t_phi *philo)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (check_end(data, philo))
			break ;
		sem_wait(data->fork_sem);
		i++;
		sem_wait(data->glob_sem);
		if (philo->state != END)
			print_message(data, get_time_ms(), philo->id, "has taken a fork");
		sem_post(data->glob_sem);
		if (data->nbr == 1)
			return (sem_post(data->fork_sem), 1);
	}
	if (check_end(data, philo))
	{
		while (i--)
			sem_post(data->fork_sem);
		return (1);
	}
	return (0);
}

int	eating(t_data *data, t_phi *philo)
{
	if (check_end(data, philo))
		return (sem_post(data->fork_sem), sem_post(data->fork_sem), 1);
	sem_wait(data->glob_sem);
	philo->state = EAT;
	philo->meal_count++;
	philo->last_meal = get_time_ms();
	print_message(data, philo->last_meal, philo->id, "is eating");
	sem_post(data->glob_sem);
	if (data->nbr_meals > 0 && philo->meal_count == data->nbr_meals)
		sem_post(data->done_sem);
	while (timediff(philo->last_meal, get_time_ms()) < data->time_to_eat)
	{
		if (check_end(data, philo))
			return (sem_post(data->fork_sem), sem_post(data->fork_sem), 1);
	}
	return (sem_post(data->fork_sem), sem_post(data->fork_sem), 0);
}

int	routine(t_phi *philo)
{
	t_data		*data;
	pthread_t	monitor_thread;
	pthread_t	end_thread;

	data = philo->data;
	if (philo->id % 2)
		usleep(2000);
	wait_start(data);
	philo->last_meal = data->start_time;
	philo->state = WAIT;
	if (create_thread(data, philo, end_monitor, &end_thread) \
	|| create_thread(data, philo, monitor, &monitor_thread))
		return (sem_post(data->end_sem), join_thread(data, &end_thread), -1);
	while (!check_end(data, philo))
	{
		if (take_forks(data, philo) \
		|| eating(data, philo) \
		|| sleeping(data, philo) \
		|| thinking(data, philo))
			break ;
	}
	if (join_thread(data, &monitor_thread) \
		||join_thread(data, &end_thread))
		return (-1);
	return (0);
}
