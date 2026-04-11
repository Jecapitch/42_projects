/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 18:47:45 by jpiscice          #+#    #+#             */
/*   Updated: 2025/08/11 01:21:29 by jpiscice         ###   ########.fr       */
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
	if (!arr || !size)
		return (-1);
	while (i < size - 1)
		if (ft_printf("%d%s", arr[i++], sep) == -1)
			return (-1);
	if (arr[i] && ft_printf("%d\n", arr[i]) == -1)
		return (-1);
	return (0);
}

static int	print_char(const char *arr, size_t size, const char sep[])
{
	size_t	i;

	i = 0;
	if (!arr || !size)
		return (-1);
	while (i < size - 1)
		if (ft_printf("%c%s", arr[i++], sep) == -1)
			return (-1);
	if (arr[i] && ft_printf("%c\n", arr[i]) == -1)
		return (-1);
	return (0);
}

static int	print_str(const char **arr, size_t size, const char sep[])
{
	size_t	i;

	i = 0;
	if (!arr || !size)
		return (-1);
	while (i < size - 1)
		if (ft_printf("%s%s", arr[i++], sep) == -1)
			return (-1);
	if (arr[i] && ft_printf("%s\n", arr[i]) == -1)
		return (-1);
	return (0);
}

int	ft_print_arr(void *arr, int data_type, const char sep[], size_t arr_size)
{
	if (!arr || !arr_size)
		return (-1);
	if (data_type == 's')
		return (print_str((const char **)arr, arr_size, sep));
	if (ft_isset(data_type, "di"))
		return (print_int((const int *)arr, arr_size, sep));
	if (data_type == 'c')
		return (print_char((const char *)arr, arr_size, sep));
	return (-1);
}
