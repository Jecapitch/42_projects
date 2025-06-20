/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:46:57 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/06 23:59:55 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

int	end_simulation(t_data *data)
{
	kill_all_processes(data);
	wait_all_processes(data);
	if (close_semaphores(data) \
		|| unlink_semaphores())
		return (-1);
	return (0);
}
