/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 21:49:29 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/30 00:58:32 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# ifndef HISTORY_FILE
#  define HISTORY_FILE		".minishell_history"
# endif

# ifndef OLDPWD_FILE
#  define OLDPWD_FILE		".minishell_oldpwd"
# endif

# ifndef NAME
#  define NAME				"minishell"
# endif

# ifndef HISTORY_SIZE
#  define HISTORY_SIZE		"1000"
# endif

# ifndef MISC
#  define PROMPT_SYMBOL		" $ " // define PROMPT_SYM_LEN accordingly
#  define PROMPT_SYM_LEN		4
#  define QUOTE_PROMPT		"quote > "
#  define DQUOTE_PROMPT		"dquote > "
#  define OPERATORS			";()&|\"\'$<>"
#  define VAR_TABLE_SIZE	256
# endif

#endif
