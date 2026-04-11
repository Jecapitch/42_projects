/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 21:49:29 by jpiscice          #+#    #+#             */
/*   Updated: 2025/08/26 02:34:47 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# ifndef HISTORY_FILE
#  define HISTORY_FILE		".minishell_history"
# endif

# ifndef NAME
#  define NAME				"minishell"
# endif

# ifndef HISTORY_SIZE
#  define HISTORY_SIZE		"1000"
# endif

# ifndef PIPE_MAX
#  define PIPE_MAX			65536
# endif

# define BUILTIN			"echo cd pwd env export unset exit"
# define HRDOC_BASE			"/tmp/heredoc_"
# define PROMPT_SYMBOL		" $ " // define PROMPT_SYM_LEN accordingly
# define PROMPT_SYM_LEN		4
# define QUOTE_PROMPT		"quote > "
# define DQUOTE_PROMPT		"dquote > "
# define BQUOTE_PROMPT		"bquote > "
# define PARSE_ERR			"minishell: parse error near '%c'\n"
# define OPERATORS			" \t~$|<>=;"
# define OPE_DQUOTE			"$\\"
# define ESC_SEQ			" nt"
# define ISENV				1
# define NOTENV				0
# define INCLUDE_UNDEF		1
# define IGNORE_UNDEF		0

#endif
