/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_iter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 01:11:50 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/11 20:29:37 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*newstr;

	if (!s || !f)
	{
		ft_err_nonnull(NULL, -1, __func__);
		return (NULL);
	}
	i = 0;
	newstr = ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (!newstr)
		return (NULL);
	while (s[i])
	{
		newstr[i] = f(i, s[i]);
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
	{
		ft_err_nonnull(NULL, -1, __func__);
		return ;
	}
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
