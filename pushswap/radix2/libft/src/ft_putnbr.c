/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 04:35:37 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/24 19:19:21 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_base(const char *base);
static void	fill(char res[256], long data[2], const char *base, const int rad);

static int	check_base(const char *base)
{
	int	ascii[128];
	int	b;
	int	c;

	b = 0;
	while (b < 128)
		ascii[b++] = 0;
	b = 0;
	while (base[b])
	{
		c = base[b];
		if (ascii[c] || c == '+' || c == '-')
			return (0);
		ascii[c]++;
		b++;
	}
	return (b);
}

static void	fill(char res[256], long data[2], const char *base, const int rad)
{
	long	n;
	long	index;

	n = data[0];
	index = data[1];
	if (n < rad)
	{
		res[index] = base[n];
		data[1]++;
		return ;
	}
	data[0] /= rad;
	fill(res, data, base, rad);
	index = data[1];
	res[index] = base[n % rad];
	data[1]++;
}

void	ft_putnbr_base_fd(long n, char *base, int fd)
{
	int		rad;
	char	res[256];
	long	data[2];

	data[0] = n;
	data[1] = 0;
	rad = check_base(base);
	if (rad < 2)
		return ;
	if (data[0] < 0)
	{
		res[0] = '-';
		data[0] *= -1;
		data[1]++;
	}
	fill(res, data, base, rad);
	res[data[1]] = '\0';
	write(fd, res, data[1]);
}

void	ft_putnbr_fd(int n, int fd)
{
	ft_putnbr_base_fd(n, BASE10, fd);
}

void	ft_putunbr_fd(t_uint n, int fd)
{
	ft_putnbr_base_fd(n, BASE10, fd);
}
