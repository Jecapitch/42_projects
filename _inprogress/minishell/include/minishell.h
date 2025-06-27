/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 21:49:29 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/27 06:16:23 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "builtin.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stddef.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <sys/param.h>
# include <errno.h>
# include <signal.h>

# ifndef HISTORY_FILE
#  define HISTORY_FILE		".minishell_history"
# endif

# ifndef OLDPWD_FILE
#  define OLDPWD_FILE		".minishell_oldpwd"
# endif

# ifndef NAME
#  define NAME				"minishell"
# endif

# define PROMPT_SYMBOL		" % " // define PROMPT_SYM_LEN accordingly
# define PROMPT_SYM_LEN		4
# define QUOTE_PROMPT		"quote > "
# define DQUOTE_PROMPT		"dquote > "
# define OPERATORS			";()&|\"\'$<>"
# define VAR_TABLE_SIZE		256

typedef struct s_shdata	t_shdata;
typedef struct s_line	t_line;
typedef struct s_var	t_var;
typedef enum e_chartype	t_chartype;
typedef enum e_quote	t_quote;
typedef int				t_signal;

extern char				**environ;
t_signal				g_signalisation;

struct s_shdata
{
	t_list	*sh_environ;
	t_list	*sh_variables;
	int		fd_history;
	int		fd_oldpwd;
	char	cwd[MAXPATHLEN + 1];
	char	oldpwd[MAXPATHLEN + 1];
	char	prompt[MAXPATHLEN + PROMPT_SYM_LEN + 1];
	char	history_file[MAXPATHLEN + 1];
	char	oldpwd_file[MAXPATHLEN + 1];
	char	home_path[MAXPATHLEN + 1];
};

struct s_line
{
	char		*line;
	t_chartype	*type;
};

struct s_var
{
	char	*key;
	char	*value;
	char	*key_val;
	size_t	keylen;
};

enum e_quote
{
	CLOSED_QUOTE = 0,
	SINGLE_QUOTE = '\'',
	DOUBLE_QUOTE = '\"'
};

enum e_chartype
{
	TEXT,
	ESCAPE,
	VAR,
	PIPE,
	HEREDOC,
	IN_REDIR,
	OUT_REDIR,
	OUT_REDIR_APPEND,
	SUBSHELL,
	TRUE_COND,
	FALSE_COND,
	SEMICOLON
};

// INIT
int		check_argc(int argc);
int		init_shdata(t_shdata *shdata);
int		init_var_list(t_list *var_list);
char	*prompt_value(t_shdata *shdata);

// PARSING
// 1. quotes
t_quote	check_quotes(const char *line);
char	*close_quotes(char *line);
// 2. strip
char	*strip_line(const char *line);

//PATHS
int		expand_path(char dest[MAXPATHLEN + 1], \
				char *path_to_expand, char *path_end);

// VARIABLES
int		export_var(t_list *var_list, char *keyval);
t_node	*search_var(const char *var, const t_list *var_list);
t_node	*set_node(t_list *var_list, t_node *node);
int		add_var_list(t_list *var_list, t_node *node, \
			char *newkey, char *newval);
int		print_var_list(const t_list *var_list, const char sep);

// HISTORY
int		open_history(t_shdata *shdata);
int		close_history(int fd);
int		load_history(t_shdata *shdata);
int		save_history(char *line, int fd);

// OLDPWD
int		open_oldpwd(t_shdata *shdata);
int		close_oldpwd(int fd);
int		load_oldpwd(t_shdata *shdata);
int		save_oldpwd(char *line, int fd);

// END
int		end_program(t_shdata *shdata);

#endif
