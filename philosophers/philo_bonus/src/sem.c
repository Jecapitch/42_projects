/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 00:10:50 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/20 23:10:51 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

int	open_semaphores(t_data *data)
{
	unlink_semaphores();
	data->start_sem = sem_open(START_SEM, O_CREAT | O_EXCL, 0644, 0);
	data->end_sem = sem_open(END_SEM, O_CREAT | O_EXCL, 0644, 0);
	data->done_sem = sem_open(DONE_SEM, O_CREAT | O_EXCL, 0644, 0);
	data->fork_sem = sem_open(FORK_SEM, O_CREAT | O_EXCL, 0644, data->nbr);
	data->glob_sem = sem_open(GLOB_SEM, O_CREAT | O_EXCL, 0644, 1);
	data->msg_sem = sem_open(MSG_SEM, O_CREAT | O_EXCL, 0644, 1);
	if (data->start_sem == SEM_FAILED \
		|| data->end_sem == SEM_FAILED \
		|| data->done_sem == SEM_FAILED \
		|| data->fork_sem == SEM_FAILED \
		|| data->glob_sem == SEM_FAILED \
		|| data->msg_sem == SEM_FAILED)
	{
		print_error(data, SEM_OPEN_ERROR);
		return (-1);
	}
	return (0);
}

int	close_semaphores(t_data *data)
{
	int	ret;

	ret = 0;
	if (data->start_sem && data->start_sem != SEM_FAILED)
		ret |= sem_close(data->start_sem);
	if (data->end_sem && data->end_sem != SEM_FAILED)
		ret |= sem_close(data->end_sem);
	if (data->done_sem && data->done_sem != SEM_FAILED)
		ret |= sem_close(data->done_sem);
	if (data->fork_sem && data->fork_sem != SEM_FAILED)
		ret |= sem_close(data->fork_sem);
	if (data->glob_sem && data->glob_sem != SEM_FAILED)
		ret |= sem_close(data->glob_sem);
	if (data->msg_sem && data->msg_sem != SEM_FAILED)
		ret |= sem_close(data->msg_sem);
	if (ret)
		print_error(data, SEM_CLOSE_ERROR);
	return (data->start_sem = NULL, data->end_sem = NULL, \
			data->done_sem = NULL, data->fork_sem = NULL, \
			data->glob_sem = NULL, data->msg_sem = NULL, \
			ret);
}

int	unlink_semaphores(void)
{
	if (sem_unlink(START_SEM) \
		|| sem_unlink(END_SEM) \
		|| sem_unlink(DONE_SEM) \
		|| sem_unlink(FORK_SEM) \
		|| sem_unlink(GLOB_SEM) \
		|| sem_unlink(MSG_SEM))
		return (-1);
	return (0);
}
