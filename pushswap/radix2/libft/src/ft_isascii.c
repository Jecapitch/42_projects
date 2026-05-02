/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:11:35 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/24 18:53:06 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(int c)
{
	return (c == ' ' \
			|| c == '\n' \
			|| c == '\t' \
			|| c == '\r' \
			|| c == '\f' \
			|| c == '\v');
}

int	ft_isascii(int n)
{
	return (0 <= n && n <= 127);
}

int	ft_isprintable(int n)
{
	return (' ' <= n && n <= '~');
}
