/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 23:22:51 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/04 00:40:20 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>
#include <limits.h>

static int	ft_isspace(int c);
static int	ft_isdigit(int c);

int	ft_isspace(int c)
{
	return ((c >= '\t' && c <= '\r') || c == ' ');
}

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi_natural(char *s)
{
	long	n;

	if (!s || !(*s))
		return (-1);
	while (ft_isspace(*s))
		s++;
	s += (*s == '+');
	if (!(*s))
		return (0);
	n = 0;
	while (*s)
	{
		if (!ft_isdigit(*s) || n > INT_MAX)
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
