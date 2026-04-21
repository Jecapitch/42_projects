/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:48:45 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/21 17:25:20 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

void	test_putc(int c, int ft_fd, int std_fd)
{
		FT(c, ft_fd);
		dprintf(ft_fd, "\n");
		STD(std_fd, "%c\n", c);
}

void	test_putn(int n, int ft_fd, int std_fd)
{
		FT(n, ft_fd);
		dprintf(ft_fd, "\n");
		STD(std_fd, "%d\n", n);
}

int	main(void)
{
	int	f = (strstr(STRF(FT), "nbr") != NULL);
	int	nbr[]  = {INT_MIN, -1, 0, 1, INT_MAX, 42, 'Z' + 12, -2133423, 1234567890};
	int	chr[] = {-12, -1, 0, 1, 2, 4, 42, '0', 'w', 'Z', '^', '$', '\n', '\a', '&'};
	int	size;
	int	ft_fd = open("traces/"STRF(FT)"_user_output", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	int	std_fd = open("traces/"STRF(FT)"_test_output", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	int n;

	if (f)
		size = sizeof(nbr) / sizeof(int);
	else
		size = sizeof(chr) / sizeof(int);
	for (int i = 0; i < size; i++)
	{
		if (f)
		{
			n = nbr[i];
			test_putn(n, ft_fd, std_fd);
		}
		else
		{
			n = chr[i];
			test_putc(n, ft_fd, std_fd);
		}
	}
	close(ft_fd);
	close(std_fd);
	return (0);
}
