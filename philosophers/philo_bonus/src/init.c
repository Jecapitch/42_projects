/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 22:32:25 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/20 06:27:49 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

void	init_data(t_data *data)
{
	data->nbr = 0;
	data->time_to_die = 0;
	data->time_to_eat = 0;
	data->time_to_sleep = 0;
	data->nbr_meals = -1;
	data->start_time = get_time_ms();
	memset(data->pid_table, 0, sizeof(data->pid_table));
	data->start_sem = NULL;
	data->end_sem = NULL;
	data->dead_sem = NULL;
	data->done_sem = NULL;
	data->fork_sem = NULL;
	data->glob_sem = NULL;
	data->msg_sem = NULL;
	return ;
}

void	init_philo(t_phi *philo)
{
	philo->id = 0;
	philo->state = END;
	philo->meal_count = 0;
	philo->last_meal = get_time_ms();
	return ;
}
