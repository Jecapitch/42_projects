/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 22:22:47 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/04 00:41:35 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>

# define ARGC_ERROR		"Wrong number of arguments\n"
# define ARG_ERROR		"Invalid argument\n"
# define MALLOC_ERROR	"Error: malloc()\n"
# define THREAD_ERROR	"Error: pthread_create()\n"
# define JOIN_ERROR		"Error: pthread_join()\n"
# define MUTEX_ERROR	"Error: pthread_mutex_init()\n"

typedef enum e_state	t_state;
typedef struct s_data	t_data;
typedef struct s_phi	t_phi;

enum e_state
{
	EAT,
	WAIT,
	DEAD
};

struct s_data
{
	int				nbr;
	int				nbr_meals;
	int				philo_done_eating;
	int				dead;
	int				start_sim;
	int				end_sim;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	size_t			death_time;
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	glob_mutex;
	t_phi			*philo;
};

struct s_phi
{
	int				id;
	int				meal_count;
	int				state;
	size_t			last_meal;
	t_data			*data;
	pthread_t		thread;
	pthread_t		monitor;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*spoon;
};

// INITIALIZE
void	check_argc(int argc);
void	init_data(t_data *data);
void	parse(char **argv, t_data *data);
void	init_philo(t_data *data);
void	init_forks(t_data *data);
void	init_glob_mutex(t_data *data);

// UTIL
int		ft_atoi_natural(char *s);
void	print_message(t_data *data, size_t time, size_t id, char *msg);

// TIME
size_t	get_time_ms(void);
size_t	timediff(size_t stard, size_t end);

// THREADS
void	create_thread(t_data *data, t_phi *philo, \
		pthread_t *thread, void *(*function)(void *));
void	join_thread(t_data *data, pthread_t thread);
void	join_all_threads(t_data *data);

// ROUTINE
void	thinking(t_data *data, t_phi *philo);
void	sleeping(t_data *data, t_phi *philo);
void	take_fork(t_data *data, t_phi *philo, pthread_mutex_t *fork);
void	eating(t_data *data, t_phi *philo);
void	*routine(void *philo);

// SIMULATION
void	launch_simulation(t_data *data);
void	wait_start(t_data *data);
void	*monitor(void *philo);

// END
void	destroy_forks(t_data *data);
void	free_table(t_data *data);
void	end_simulation(t_data *data);

#endif
