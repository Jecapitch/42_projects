/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 22:21:59 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/20 07:26:19 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

int	main(int argc, char **argv)
{
	t_data		data;
	pthread_t	all_done_thread;

	if (check_argc(argc) == -1)
		return (EXIT_FAILURE);
	init_data(&data);
	if (parse(argv, &data) == -1)
		return (EXIT_FAILURE);
	if (open_semaphores(&data) == -1)
		return (EXIT_FAILURE);
	if (create_thread(&data, &data, done_monitor, &all_done_thread) == -1)
		return (end_simulation(&data), EXIT_FAILURE);
	if (launch_simulation(&data) == -1)
		return (end_simulation(&data), EXIT_FAILURE);
	waitpid(-1, NULL, 0);
	if (join_thread(&data, &all_done_thread) == -1)
		return (end_simulation(&data), EXIT_FAILURE);
	return (end_simulation(&data));
}
