/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 21:49:29 by jpiscice          #+#    #+#             */
/*   Updated: 2025/08/26 18:25:11 by jpiscice         ###   ########.fr       */
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
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <sys/param.h>
# include <sys/stat.h>
# include <dirent.h>
# include <sysexits.h>
# include <errno.h>
# include <signal.h>

// INIT
int			init_shdata(t_shdata *shdata, t_line *line);
int			init_variables(t_shdata *shdata);
int			prompt_value(t_shdata *shdata);

// LINE STRUCTURE
t_line		*alloc_line(char *s, t_flag *flags);
void		*free_line_struct(t_line *line);
void		free_cmdline(t_line *line);
size_t		get_pipe_nbr(t_line **pipeline);

// PARSING
char		*line_read(t_shdata *shdata, t_line *line);
size_t		loop_to_set(t_line *line, size_t i, char *set);
// quotes
int			is_quote(int c);
int			get_quote_state(t_line *line, size_t i);
t_quote		check_quotes(t_line *line, size_t len);
char		*close_quotes(t_line *line);
// pipeline
int			check_end_pipe(t_line *line, size_t len);
int			check_pipes(t_line *line);
int			check_pipeline(t_line *line, size_t len);
char		*close_pipeline(t_line *line);
// backslash
int			check_bs(t_line *line, size_t len);
char		*close_bs(t_line *line);
// redirections
int			check_end_redirect(t_line *line, size_t len);
int			check_redirect(t_line *line);
// strip
char		*convert_nl(char *line);
char		*strip_line(char *line);
// flags and escapes
//// set flagged line
int			preflag_line(t_line *line);
int			flag_line(t_line *line);
int			init_flag_fun(t_line *line, size_t *i, size_t *j, char **newline);
void		init_flag_value(t_line *line, size_t i, char *newline, size_t j);
void		opening_quote_flag(t_line *line, size_t *i, size_t *j);
void		redirect_flag(t_line *line, size_t *i, char *newline, size_t *j);
int			symbol_flag(t_line *line, size_t i);
void		print_flag_line(t_line *line);
////// helpers
//// escape sequences
void		escaping(t_line *line, size_t *i, char *newline, size_t *j);
void		escape_regular(t_line *line, size_t *i, char *newline, size_t *j);
void		escape_quote(t_line *line, size_t *i, char *newline, size_t *j);
void		escape_dquote(t_line *line, size_t *i, char *newline, size_t *j);

// SPLIT LINE ON FLAGS
t_line		**split_line(t_line *line, const t_flag flag);
t_line		**free_splitline(t_line **splitline);

// SUBSTITUTIONS
char		*expand_variable(t_shdata *shdata, t_line *line);
char		*expand_heredoc(t_shdata *shdata, char *text);
void		expand_arg_rm_quote(t_shdata *shdata, t_line **arg, size_t index);
void		remove_quotes(t_line *line);

// COMMANDS
//// build
int			make_struct_cmd(t_shdata *shdata, t_pipeline *pipeline, \
							t_cmd *cmd, size_t index);
int			get_cmd_args(t_shdata *shdata, t_cmd *cmd);
void		free_cmd(void *cmd);
//// get path
int			is_path(char *name);
int			get_command_bin_path(t_cmd *cmd);
int			is_valid_exec(char *path, char *name);
//// process
int			process_cmds(t_shdata *shdata, t_line *line);
int			prepare_cmds(t_shdata *shdata, t_pipeline *pipeline, t_line *line);
void		free_pipeline(t_pipeline *pipeline);

// EXEC
//// redirection
int			redirect(t_list *redir);
int			add_redir(t_shdata *shdata, t_cmd *cmd, size_t index);
char		*name_heredoc(t_redir *heredoc);
int			prepare_heredoc(t_shdata *shdata, t_redir *redir);
int			is_redir(t_flag flag);
void		free_redir(void *redir_struct);
//// pipes
int			open_pipes(t_pipe **pfd, size_t nbr_pipes);
int			dup_pipes(t_pipe *pfd, size_t index, size_t nbr_pipes);
void		close_pipes(t_pipe *pfd, size_t index);
int			wait_all_children(t_pipeline *pipeline, size_t n);
int			checkstatus(int status);
//// execution
int			execute(t_shdata *shdata, t_pipeline *pipeline, \
					t_cmd *cmd, t_pipe **pfd);

// VARIABLES
// read
char		*get_var_key(t_node_2 *node);
char		*get_var_val(t_node_2 *node);
t_node_2	*search_var(t_list_2*var_list, const char *var_key);
int			print_var_list(const t_list_2*var_list, int sep, \
					int isenv, int include_blank);
size_t		var_key_len(char *variable);
// handle
t_list_2	*init_var_list(void);
t_var		*parse_var(char *variable, int isenv);
int			set_var(t_shdata *shdata, char *variable, int isenv);
int			set_node_2(t_list_2*var_list, t_node_2 *node, t_var *var);
// free
void		clear_var(void *var_struct);
void		free_var(void *var_struct);

// ENVIRON
char		**duplicate_env(void);
int			load_environ(t_shdata *shdata);
void		update_shdata_env(t_shdata *shdata, char *key, char *val);
int			update_environ(t_shdata *shdata);
char		**environ_arr(t_list_2*var_list);
int			set_pwd(t_shdata *shdata);

// HISTORY
int			open_history(t_shdata *shdata, int oflag);
int			load_history(t_shdata *shdata);
int			history_add(t_shdata *shdata, char *line);
int			save_history(t_shdata *shdata);
char		*expand_path(t_list_2 *var_list, char *to_expand, char *path_end);

// END
int			set_exit_var(t_shdata *shdata, int exit_status);
int			end_program(t_shdata *shdata);
void		free_shdata(t_shdata *shdata);

// SIGNALS
void		set_sigint_handler(void sigint(int));
void		set_sigquit_handler(void sigquit(int));
void		line_sigint_handler(int sig);
void		inter_sigint_handler(int sig);

// FD
int			isopen(int fd);
int			close_if_isopen(int fd);
int			close_all_fd(t_pipe *fd, size_t size);
int			dup_std(t_shdata *shdata);
int			reset_std(t_shdata *shdata);

#endif
