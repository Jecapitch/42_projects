/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 22:21:59 by jpiscice          #+#    #+#             */
/*   Updated: 2025/05/29 05:16:47 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	main(int argc, char **argv)
{
	t_data	data;

	check_argc(argc);
	init_data(&data);
	parse(argv, &data);
	init_forks(&data);
	init_philo(&data);
	init_glob_mutex(&data);
	launch_simulation(&data);
	join_all_threads(&data);
	end_simulation(&data);
	return (EXIT_SUCCESS);
}
