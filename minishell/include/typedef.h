/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 21:49:29 by jpiscice          #+#    #+#             */
/*   Updated: 2025/08/26 02:24:02 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H

# include "define.h"

typedef struct s_shdata		t_shdata;
typedef struct s_line		t_line;
typedef struct s_cmd		t_cmd;
typedef struct s_pipeline	t_pipeline;
typedef struct s_redir		t_redir;
typedef struct s_var		t_var;
typedef enum e_flag			t_flag;
typedef enum e_open			t_open;
typedef enum e_quote		t_quote;
typedef enum e_exit			t_exit;
typedef int					t_signal;
typedef int					t_pipe[2];

extern char					**environ;
t_signal					g_signal;

enum e_quote
{
	CLOSED_QUOTE = 0,
	SINGLE_QUOTE = '\'',
	DOUBLE_QUOTE = '\"',
	BACK_QUOTE = '`'
};

enum e_flag
{
	F_EOL = 0x0,
	F_REGULAR = 0x1,
	F_SPACE = 0x2,
	F_QUOTE = 0x10,
	F_DQUOTE = 0x20,
	F_DOLLAR = 0x100,
	F_TILDE = 0x200,
	F_VAR = 0x400,
	F_EQUAL = 0x800,
	F_QUEST_MARK = 0x1000,
	F_STAR = 0x2000,
	F_IN_REDIR = 0x10000,
	F_HEREDOC = 0x20000,
	F_OUT_REDIR = 0x40000,
	F_OUT_APPEND = 0x80000,
	F_PIPE = 0x100000,
	F_SEMICOLON = 0x200000,
	F_PARENTHESIS = 0x1000000,
	F_TRUE_COND = 0x2000000,
	F_FALSE_COND = 0x4000000
};

enum e_open
{
	IN_OPEN = O_RDONLY | O_CLOEXEC,
	OUT_OPEN = O_WRONLY | O_CREAT | O_TRUNC | O_CLOEXEC,
	APP_OPEN = O_WRONLY | O_CREAT | O_APPEND | O_CLOEXEC
};

enum e_exit
{
	EX_SUCCESS = 0,
	EX_FAILURE = 1,
	EX_MISUSE = 2,
	EX_NOTEXEC = 126,
	EX_NOTFOUND = 127,
	EX_INVALID = 128
};

struct s_shdata
{
	t_list_2	*variables;
	t_list		*history;
	char		**sh_environ;
	t_line		**cmds;
	char		**builtin;
	char		*ptr_home_path;
	char		*ptr_cwd;
	char		*ptr_oldpwd;
	char		*ptr_prompt;
	char		*ptr_history_file;
	size_t		history_size;
	int			fd_history;
	int			stdinfd;
	int			stdoutfd;
	int			stderrfd;
};

struct s_line
{
	char	*line;
	t_flag	*flags;
	size_t	len;
	int		quote_state;
};

struct s_cmd
{
	t_line	**cmdflag;
	t_list	*redirections;
	char	**argv;
	char	*executable;
	size_t	argc;
	size_t	index;
	int		pid;
	int		isbuiltin;
	int		ischild;
};

struct s_pipeline
{
	t_line		**pipeline;
	t_list		*cmdlist;
	int			*pids;
	size_t		nbr_pipes;
	int			exit_status;
};

struct s_redir
{
	char	*name;
	char	*delim;
	t_flag	*flags;
	t_flag	type;
	int		fd;
	int		isquoted;
};

struct s_var
{
	char	*key;
	char	*value;
	char	*keyval;
	int		equal;
	size_t	keylen;
	size_t	vallen;
	int		isenv;
};

#endif
