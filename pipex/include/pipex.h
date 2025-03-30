/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 23:11:29 by jpiscice          #+#    #+#             */
/*   Updated: 2025/03/27 23:35:54 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <libft.h>
# include <sys/wait.h>
# include <errno.h>

extern char				**environ;
typedef struct s_arg	t_arg;

struct s_arg
{
	char	*infile;
	char	*outfile;
	char	**cmd1;
	char	**cmd2;
	char	*path1;
	char	*path2;
};

// UTIL
void	init(t_arg *args);
void	arg_parse(char **argv, t_arg *args);
void	free_arg(t_arg *args);

// CMD PATH
void	splitcmd(t_arg *args, char *cmd1, char *cmd2);
void	buildpath(t_arg *args);

// PROCESSES
void	process(pid_t pid, int fd[2], t_arg *args);

#endif
