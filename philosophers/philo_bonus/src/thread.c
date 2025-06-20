/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 01:28:02 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/06 22:50:11 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

int	create_thread(t_data *data, void *arg, \
		void *(*function)(void *), pthread_t *thread)
{
	if (pthread_create(thread, NULL, function, arg))
	{
		print_error(data, THREAD_ERROR);
		return (-1);
	}
	return (0);
}

int	join_thread(t_data *data, pthread_t *thread)
{
	if (pthread_join(*thread, NULL))
	{
		print_error(data, JOIN_ERROR);
		return (-1);
	}
	return (0);
}

int	detach_thread(t_data *data, pthread_t *thread)
{
	if (pthread_detach(*thread))
	{
		print_error(data, DETACH_ERROR);
		return (-1);
	}
	return (0);
}
