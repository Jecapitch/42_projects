/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 22:22:47 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/20 06:29:43 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <signal.h>

# define ARGC_ERROR			"Wrong number of arguments\n"
# define ARG_ERROR			"Invalid argument\n"
# define MALLOC_ERROR		"malloc error\n"
# define THREAD_ERROR		"pthread_create error\n"
# define JOIN_ERROR			"pthread_join error\n"
# define DETACH_ERROR		"pthread_detach error\n"
# define SEM_OPEN_ERROR		"sem_open error\n"
# define SEM_CLOSE_ERROR	"sem_close error\n"
# define SEM_UNLINK_ERROR	"sem_unlink error\n"
# define FORK_ERROR			"fork error\n"
# define START_SEM			"/start_sem"
# define END_SEM			"/end_sem"
# define DEAD_SEM			"/dead_sem"
# define DONE_SEM			"/done_sem"
# define FORK_SEM			"/fork_sem"
# define GLOB_SEM			"/glob_sem"
# define MSG_SEM			"/msg_sem"
# define MAX_SIZE			200

typedef enum e_state	t_state;
typedef struct s_data	t_data;
typedef struct s_phi	t_phi;

enum e_state
{
	EAT,
	WAIT,
	END
};

struct s_data
{
	int				nbr;
	int				nbr_meals;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	size_t			death_time;
	sem_t			*start_sem;
	sem_t			*end_sem;
	sem_t			*dead_sem;
	sem_t			*done_sem;
	sem_t			*fork_sem;
	sem_t			*glob_sem;
	sem_t			*msg_sem;
	pid_t			pid_table[MAX_SIZE];
};

struct s_phi
{
	int				id;
	int				meal_count;
	int				state;
	size_t			last_meal;
	t_data			*data;
};

// INITIALIZE
int		check_argc(int argc);
void	init_data(t_data *data);
int		parse(char **argv, t_data *data);
void	init_philo(t_phi *philo);

// TIME
size_t	get_time_ms(void);
size_t	timediff(size_t start, size_t end);

// SEMAPHORES
int		open_semaphores(t_data *data);
int		close_semaphores(t_data *data);
int		unlink_semaphores(void);

// PROCESSES
int		create_process(t_data *data, size_t i);
void	wait_all_processes(t_data *data);
void	kill_all_processes(t_data *data);

// THREADS
int		create_thread(t_data *data, void *arg, \
			void *(*function)(void *), pthread_t *thread);
int		join_thread(t_data *data, pthread_t *thread);
int		detach_thread(t_data *data, pthread_t *thread);

// ROUTINE
int		thinking(t_data *data, t_phi *philo);
int		sleeping(t_data *data, t_phi *philo);
int		take_forks(t_data *data, t_phi *philo);
int		eating(t_data *data, t_phi *philo);
int		routine(t_phi *philo);

// SIMULATION
int		launch_simulation(t_data *data);
void	wait_start(t_data *data);
void	*monitor(void *ptr_philo);
void	*end_monitor(void *ptr_data);
void	*done_monitor(void *ptr_data);

// END
int		end_simulation(t_data *data);

// UTILS
size_t	ft_strlen(char *s);
int		ft_atoi_natural(char *s);
void	print_message(t_data *data, size_t time, size_t id, char *msg);
void	print_error(t_data *data, char *msg);
int		check_end(t_data *data, t_phi *philo);

#endif
