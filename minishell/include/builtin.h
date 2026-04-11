/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 08:39:43 by jpiscice          #+#    #+#             */
/*   Updated: 2025/08/23 00:27:31 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "typedef.h"

int	bi_echo(char **args);
int	bi_cd(t_shdata *shdata, char **args);
int	bi_pwd(void);
int	bi_env(t_shdata *shdata, char **args);
int	bi_export(t_shdata *shdata, char **args);
int	bi_unset(t_shdata *shdata, char **args);
int	bi_exit(t_shdata *shdata, t_pipeline *pipeline, char **args, int status);

#endif
