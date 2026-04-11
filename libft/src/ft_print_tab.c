/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 18:47:45 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/11 00:56:41 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	print_int(const int *tab, size_t size, const char sep[]);
static int	print_char(const char *tab, size_t size, const char sep[]);
static int	print_str(const char **tab, size_t size, const char sep[]);

static int	print_int(const int *tab, size_t size, const char sep[])
{
	size_t	i;

	i = 0;
	while (i < size - 1)
		if (ft_printf("%d%s", tab[i++], sep) == -1)
			return (-1);
	if (tab[i] && ft_printf("%d\n", tab[i]) == -1)
		return (-1);
	return (0);
}

static int	print_char(const char *tab, size_t size, const char sep[])
{
	size_t	i;

	i = 0;
	while (i < size - 1)
		if (ft_printf("%c%s", tab[i++], sep) == -1)
			return (-1);
	if (tab[i] && ft_printf("%c\n", tab[i]) == -1)
		return (-1);
	return (0);
}

static int	print_str(const char **tab, size_t size, const char sep[])
{
	size_t	i;

	i = 0;
	while (i < size - 1)
		if (ft_printf("%s%s", tab[i++], sep) == -1)
			return (-1);
	if (tab[i] && ft_printf("%s\n", tab[i]) == -1)
		return (-1);
	return (0);
}

int	ft_print_tab(void *tab, int data_type, const char sep[], size_t tab_size)
{
	if (!tab)
	{
		ft_err_nonnull(NULL, -1, __func__);
		return (-1);
	}
	if (!ft_isset(data_type, "sdic"))
	{
		ft_log(NULL, -1, __func__, "data type must be [sdic]");
		return (-1);
	}
	if (!tab_size)
		return (0);
	if (data_type == 's')
		return (print_str((const char **)tab, tab_size, sep));
	if (ft_isset(data_type, "di"))
		return (print_int((const int *)tab, tab_size, sep));
	if (data_type == 'c')
		return (print_char((const char *)tab, tab_size, sep));
	return (-1);
}
