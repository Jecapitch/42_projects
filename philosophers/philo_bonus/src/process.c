/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 01:28:02 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/20 07:05:19 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

int	create_process(t_data *data, size_t i)
{
	pid_t	child;
	t_phi	philo;

	init_philo(&philo);
	child = fork();
	if (child < 0)
	{
		print_error(data, FORK_ERROR);
		return (exit(EXIT_FAILURE), -1);
	}
	else if (child > 0)
		return (data->pid_table[i] = child, 0);
	else
	{
		philo.data = data;
		philo.id = i + 1;
		if (routine(&philo) || close_semaphores(data))
			return (exit(EXIT_FAILURE), -1);
		return (exit(EXIT_SUCCESS), 0);
	}
}

void	wait_all_processes(t_data *data)
{
	size_t	i;
	pid_t	*pid;
	int		status;

	i = 0;
	pid = data->pid_table;
	while (i++ < (size_t)data->nbr)
	{
		if (*pid > 0)
			waitpid(*pid, &status, 0);
		*pid = -1;
		pid++;
	}
}

void	kill_all_processes(t_data *data)
{
	size_t	i;
	pid_t	*pid;

	i = 0;
	pid = data->pid_table;
	while (i++ < (size_t)data->nbr)
	{
		if (!kill(*pid, 0))
			kill(*pid, SIGTERM);
		usleep(1000);
		if (!kill(*pid, 0))
			kill(*pid, SIGKILL);
		pid++;
	}
	return ;
}
