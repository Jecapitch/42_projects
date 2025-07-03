/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 18:47:45 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/26 20:23:13 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	print_int(const int *arr, size_t size, const char sep[]);
static int	print_char(const char *arr, size_t size, const char sep[]);
static int	print_str(const char **arr, size_t size, const char sep[]);

static int	print_int(const int *arr, size_t size, const char sep[])
{
	size_t	i;

	i = 0;
	while (i < size - 1)
		if (ft_printf("%d%s", arr[i++], sep) == -1)
			return (-1);
	if (ft_printf("%d", arr[i]) == -1 \
		|| ft_printf("\n") == -1)
		return (-1);
	return (0);
}

static int	print_char(const char *arr, size_t size, const char sep[])
{
	size_t	i;

	i = 0;
	while (i < size - 1)
		if (ft_printf("%c%s", arr[i++], sep) == -1)
			return (-1);
	if (ft_printf("%c", arr[i]) == -1 \
		|| ft_printf("\n") == -1)
		return (-1);
	return (0);
}

static int	print_str(const char **arr, size_t size, const char sep[])
{
	size_t	i;

	i = 0;
	while (i < size - 1)
		if (ft_printf("%s%s", arr[i++], sep) == -1)
			return (-1);
	if (ft_printf("%s", arr[i]) == -1 \
		|| ft_printf("\n") == -1)
		return (-1);
	return (0);
}

int	ft_print_arr(void *arr, int data_type, const char sep[], size_t arr_size)
{
	if (data_type == 's')
		return (print_str((const char **)arr, arr_size, sep));
	if (ft_isset(data_type, "di"))
		return (print_int((const int *)arr, arr_size, sep));
	if (data_type == 'c')
		return (print_char((const char *)arr, arr_size, sep));
	return (-1);
}
