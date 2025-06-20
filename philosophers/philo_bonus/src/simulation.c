/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 00:10:50 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/20 23:28:33 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

int	launch_simulation(t_data *data)
{
	size_t	i;

	i = 0;
	data->start_time = get_time_ms();
	while (i < (size_t)data->nbr)
		if (create_process(data, i++) == -1)
			return (-1);
	sem_post(data->start_sem);
	return (0);
}

void	wait_start(t_data *data)
{
	sem_wait(data->start_sem);
	sem_post(data->start_sem);
}

void	*monitor(void *ptr_philo)
{
	t_phi	*philo;
	t_data	*data;
	size_t	time;

	philo = (t_phi *)ptr_philo;
	data = philo->data;
	while (!check_end(data, philo))
	{
		sem_wait(data->glob_sem);
		time = get_time_ms();
		if (philo->state != END \
			&& timediff(philo->last_meal, time) > data->time_to_die)
		{
			if (philo->state != END)
				print_message(data, time, philo->id, "died");
			break ;
		}
		sem_post(data->glob_sem);
	}
	sem_post(data->end_sem);
	return (NULL);
}

void	*done_monitor(void *ptr_data)
{
	t_data	*data;
	size_t	i;

	data = (t_data *)ptr_data;
	i = 0;
	while (i++ < (size_t)data->nbr)
		sem_wait(data->done_sem);
	sem_wait(data->glob_sem);
	sem_post(data->end_sem);
	return (NULL);
}

void	*end_monitor(void *ptr_philo)
{
	t_phi	*philo;
	t_data	*data;
	size_t	i;

	philo = (t_phi *)ptr_philo;
	data = philo->data;
	sem_wait(data->end_sem);
	sem_post(data->end_sem);
	philo->state = END;
	i = 0;
	while (i++ < (size_t)data->nbr)
	{
		sem_post(data->end_sem);
		sem_post(data->done_sem);
	}
	usleep(200000);
	sem_post(data->glob_sem);
	return (NULL);
}
