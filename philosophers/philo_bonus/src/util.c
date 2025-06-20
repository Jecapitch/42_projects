/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 23:22:51 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/20 07:26:54 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>
#include <limits.h>

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	ft_atoi_natural(char *s)
{
	long	n;

	if (!s || !(*s))
		return (-1);
	while (*s == ' ' || (*s >= '\t' && *s <= '\r'))
		s++;
	s += (*s == '+');
	if (!(*s))
		return (0);
	n = 0;
	while (*s)
	{
		if (*s < '0' || *s > '9' || n > INT_MAX)
			return (0);
		n *= 10;
		n += (*s - '0');
		s++;
	}
	return (n);
}

void	print_message(t_data *data, size_t time, size_t id, char *msg)
{
	printf("%zu ms %zu %s\n", timediff(data->start_time, time), id, msg);
	return ;
}

void	print_error(t_data *data, char *msg)
{
	int	locked;

	locked = 0;
	if (data->msg_sem && data->msg_sem != SEM_FAILED)
	{
		sem_wait(data->msg_sem);
		locked = 1;
	}
	write(2, msg, ft_strlen(msg));
	if (locked)
		sem_post(data->msg_sem);
}

int	check_end(t_data *data, t_phi *philo)
{
	sem_wait(data->glob_sem);
	if (philo->state == END)
		return (sem_post(data->glob_sem), 1);
	return (sem_post(data->glob_sem), 0);
}
