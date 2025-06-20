/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 22:32:25 by jpiscice          #+#    #+#             */
/*   Updated: 2025/05/31 04:22:15 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static void	set_forks(t_phi *philo, t_data *data, size_t i);

static void	set_forks(t_phi *philo, t_data *data, size_t i)
{
	pthread_mutex_t	*fork_mutex;
	int				i_even;
	size_t			i_plus;

	fork_mutex = data->fork_mutex;
	i_even = i & 1;
	i_plus = (i + 1) % data->nbr;
	if (i_even)
	{
		philo->fork = &fork_mutex[i];
		philo->spoon = &fork_mutex[i_plus];
		return ;
	}
	philo->fork = &fork_mutex[i_plus];
	philo->spoon = &fork_mutex[i];
	return ;
}

void	init_data(t_data *data)
{
	data->nbr = INT_MAX;
	data->time_to_die = INT_MAX;
	data->time_to_eat = INT_MAX;
	data->time_to_sleep = INT_MAX;
	data->nbr_meals = -1;
	data->philo_done_eating = 0;
	data->dead = 0;
	data->start_sim = 0;
	data->end_sim = 0;
	data->start_time = get_time_ms();
	data->fork_mutex = NULL;
	data->philo = NULL;
	return ;
}

void	init_philo(t_data *data)
{
	size_t	i;
	t_phi	*philo;

	philo = NULL;
	data->philo = malloc(data->nbr * sizeof(t_phi));
	if (!data->philo)
	{
		write(2, MALLOC_ERROR, sizeof(MALLOC_ERROR));
		end_simulation(data);
		exit(EXIT_FAILURE);
	}
	memset(data->philo, 0, sizeof(t_phi) * data->nbr);
	i = 0;
	while (i < (size_t)data->nbr)
	{
		philo = &data->philo[i];
		philo->id = i + 1;
		set_forks(philo, data, i);
		philo->state = EAT;
		philo->meal_count = 0;
		philo->data = data;
		i++;
	}
	return ;
}

void	init_forks(t_data *data)
{
	size_t	i;

	data->fork_mutex = malloc(data->nbr * sizeof(pthread_mutex_t));
	if (!data->fork_mutex)
	{
		write(2, MALLOC_ERROR, sizeof(MALLOC_ERROR));
		free_table(data);
		exit(EXIT_FAILURE);
	}
	memset(data->fork_mutex, 0, sizeof(pthread_mutex_t) * data->nbr);
	i = 0;
	while (i < (size_t)data->nbr)
	{
		if (pthread_mutex_init(&data->fork_mutex[i], NULL) == -1)
		{
			write(2, MUTEX_ERROR, sizeof(MUTEX_ERROR));
			end_simulation(data);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return ;
}

void	init_glob_mutex(t_data *data)
{
	if (pthread_mutex_init(&data->glob_mutex, NULL) == -1)
	{
		write(2, MUTEX_ERROR, sizeof(MUTEX_ERROR));
		end_simulation(data);
		exit(EXIT_FAILURE);
	}
}
