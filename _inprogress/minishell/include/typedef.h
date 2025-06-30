/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 21:49:29 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/30 00:46:09 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H

# include "define.h"

typedef struct s_shdata	t_shdata;
typedef struct s_line	t_line;
typedef struct s_var	t_var;
typedef enum e_chartype	t_chartype;
typedef enum e_quote	t_quote;
typedef int				t_signal;

extern char				**environ;
t_signal				g_signal;

struct s_shdata
{
	t_list	*environ;
	t_list	*variables;
	t_list	*history;
	char	*ptr_home_path;
	char	*ptr_cwd;
	char	*ptr_oldpwd;
	char	*ptr_prompt;
	char	*ptr_history_file;
	char	*ptr_oldpwd_file;
	size_t	history_size;
	int		fd_history;
	int		fd_oldpwd;
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
	char	*keyval;
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

#endif
