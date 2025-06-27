/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 08:39:43 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/27 06:37:02 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "minishell.h"

typedef struct s_shdata	t_shdata;
typedef struct s_var	t_var;

int		cd(const char *path, t_shdata *shdata);
int		pwd(void);
int		echo(char **args);

// ENVIRON
int		export_env(t_shdata *shdata, char *key_val);
int		load_environ(t_shdata *shdata);
int		print_env_list(t_shdata *shdata, char sep);

#endif
