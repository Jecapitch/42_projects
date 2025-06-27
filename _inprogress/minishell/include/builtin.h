/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 08:39:43 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/27 22:53:26 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "minishell.h"

typedef struct s_shdata	t_shdata;
typedef struct s_var	t_var;

extern char				**environ;

int		cd(const char *path, t_shdata *shdata);
int		pwd(const t_shdata *shdata);
int		echo(const char **args);

// ENVIRON
int		print_env_list(t_shdata *shdata, char sep);

#endif
