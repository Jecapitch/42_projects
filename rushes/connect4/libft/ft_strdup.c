/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthys <nthys@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:15:46 by nthys             #+#    #+#             */
/*   Updated: 2025/10/16 17:15:46 by nthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*cpy;
	char	*beg;

	cpy = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (cpy == NULL)
		return (NULL);
	beg = cpy;
	while (*s)
		*cpy++ = *s++;
	*cpy = '\0';
	return (beg);
}
