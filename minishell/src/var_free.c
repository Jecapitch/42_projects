/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 23:31:10 by jpiscice          #+#    #+#             */
/*   Updated: 2025/08/26 13:13:02 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clear_var(void *var_struct)
{
	t_var	*var;

	var = NULL;
	if (!var_struct)
		return ;
	var = (t_var *)var_struct;
	var->key = ft_free_safe(var->key);
	var->value = ft_free_safe(var->value);
	var->keyval = ft_free_safe(var->keyval);
	ft_bzero(var, sizeof(t_var));
}

void	free_var(void *var_struct)
{
	clear_var(var_struct);
	var_struct = ft_free_safe(var_struct);
}
