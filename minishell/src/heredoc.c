/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 02:03:33 by jpiscice          #+#    #+#             */
/*   Updated: 2025/08/26 05:17:01 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	interrupt_heredoc(t_shdata *shdata, t_redir *redir, char *text);
static int	write_heredoc_file(t_shdata *shdata, t_redir *heredoc, char *text);

char	*name_heredoc(t_redir *heredoc)
{
	static int		count = 0;
	char			*name;
	char			*suffix;

	name = NULL;
	suffix = ft_itoa(count);
	if (!suffix)
		return (NULL);
	name = ft_strjoin(HRDOC_BASE, suffix);
	free(suffix);
	if (!name)
		return (NULL);
	heredoc->name = name;
	count++;
	return (name);
}

static int	write_heredoc_file(t_shdata *shdata, t_redir *heredoc, char *text)
{
	int		fd;
	int		p_ret;

	p_ret = 0;
	fd = open(heredoc->name, O_CREAT | O_WRONLY, 0644);
	if (fd == -1)
		return (ft_free_safe(text), 1);
	if (!text)
		return (close_if_isopen(fd), 0);
	if (!heredoc->isquoted)
		text = expand_heredoc(shdata, text);
	if (!text)
		return (close_if_isopen(fd), text = ft_free_safe(text), 1);
	p_ret = ft_fprintf(fd, "%s", text);
	close_if_isopen(fd);
	text = ft_free_safe(text);
	return (p_ret == -1);
}

static int	interrupt_heredoc(t_shdata *shdata, t_redir *redir, char *text)
{
	if (g_signal == SIGINT)
		return (dup2(shdata->stdinfd, STDIN_FILENO), ft_free_safe(text), 1);
	ft_printf("Unexpected end-of-file, expected %s\n", redir->delim);
	set_sigint_handler(SIG_IGN);
	return (write_heredoc_file(shdata, redir, text));
}

int	prepare_heredoc(t_shdata *shdata, t_redir *redir)
{
	char	*rline;
	char	*text;
	size_t	len;

	rline = NULL;
	text = NULL;
	if (!redir)
		return (0);
	len = ft_strlen(redir->delim);
	set_sigint_handler(line_sigint_handler);
	while (1)
	{
		rline = readline("hrdoc > ");
		if (!rline)
			return (interrupt_heredoc(shdata, redir, text));
		if (ft_strncmp(rline, redir->delim, len + 1) == 0)
			return (rline = ft_free_safe(rline), \
					set_sigint_handler(SIG_IGN), \
					write_heredoc_file(shdata, redir, text));
		ft_strappend(&text, rline);
		ft_strappend(&text, "\n");
		rline = ft_free_safe(rline);
		if (!text)
			return (1);
	}
}
