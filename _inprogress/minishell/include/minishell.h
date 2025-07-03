/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 21:49:29 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/30 23:36:36 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "builtin.h"
# include "typedef.h"
# include "define.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stddef.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <sys/param.h>
# include <sysexits.h>
# include <errno.h>
# include <signal.h>

// INIT
void	set_zero(t_shdata *data);
int		init_shdata(t_shdata *shdata);
int		prompt_value(t_shdata *shdata);

// PARSING
// 1. quotes
t_quote	check_quotes(const char *line);
char	*close_quotes(char *line);
// 2. strip
char	*strip_line(char *line);

//PATHS
int		expand_path(t_list *var_list, char dest[PATH_MAX + 1], \
				char *path_to_expand, char *path_end);

// VARIABLES
t_list	*init_var_list(void);
char	*get_var_key(t_node *node);
char	*get_var_val(t_node *node);
t_node	*search_var(const char *var_key, const t_list *var_list);
int		print_var_list(const t_list *var_list, const char sep);
int		export_var(t_shdata *shdata, t_list *var_list, \
					char *key, char *value);
int		add_var_list(t_list *var_list, t_node *node, \
						char *newkey, char *newval);
t_node	*reset_node(t_list *var_list, t_node *node);
void	clear_var(void *node_content);
int		export_var_default(t_shdata *shdata);

// ENVIRON
int		load_environ(t_shdata *shdata);
void	update_shdata_env(t_shdata *shdata);

// HISTORY
int		open_history(t_shdata *shdata, int oflag);
int		close_history(int fd);
int		load_history(t_shdata *shdata);
int		history_add(t_shdata *shdata, char *line);
int		save_history(t_shdata *shdata);

// END
int		end_program(t_shdata *shdata);

#endif
