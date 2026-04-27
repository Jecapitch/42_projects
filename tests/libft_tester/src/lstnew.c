/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:48:45 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/27 23:29:54 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

int	null_check(void)
{
	switch (fork())
	{
		case -1:
		{
			perror("fork");
			return (0);
		}
		case 0:
		{
			int	devnull = open("/dev/null", O_WRONLY);
			if (devnull != -1)
			{
				dup2(devnull, STDERR_FILENO);
				close(devnull);
			}
			t_list	*node = FT(NULL);
			int		ret = (node && node->content);
			tester_ft_free_safe(node->content);
			free(node);
			exit(ret);
		}
		default:
		{
			int	status;
			wait(&status);
			if (WIFSIGNALED(status) || WEXITSTATUS(status))
				return (printf(STRF(FT(NULL))": "ERROR"\n"), 1);
			return (0);
		}
	}
}

int	free_not_alloc(char *s)
{
	switch (fork())
	{
		case -1:
		{
			perror("fork: retry");
			exit (0);
		}
		case 0:
		{
			t_list	*node = ft_lstnew(s);
			char	*tmp = node->content;
			int	devnull = open("/dev/null", O_WRONLY);

			if (devnull != -1)
			{
				dup2(devnull, STDERR_FILENO);
				close(devnull);
			}
			free(node);
			free(tmp);
			exit(0);
		}
		default:
		{
			int	status;
			int	ret = 0;
			wait(&status);
			if (!WIFSIGNALED(status))
			{
				ret = 1;
				printf(STRF(FT(char *s))": "RED"Allocate when shouldn't\n"CRESET);
			}
			return (ret);
		}
	}
}

int	alloc_content(char *s)
{
	switch (fork())
	{
		case -1:
		{
			perror("fork: retry");
			exit (0);
		}
		case 0:
		{
			t_list	*node = ft_lstnew(strdup(s));
			char	*tmp = node->content;
			int	devnull = open("/dev/null", O_WRONLY);

			if (devnull != -1)
			{
				dup2(devnull, STDERR_FILENO);
				close(devnull);
			}
			free(node);
			free(tmp);
			exit(0);
		}
		default:
		{
			int	status;
			int	ret = 0;
			wait(&status);
			if (WIFSIGNALED(status))
			{
				printf(STRF(FT(s))": "RED"Doesn't allocate when should\n"CRESET);
				ret = 1;
			}
			return (ret);
		}
	}
}

int	char_content(char *s)
{
	t_list	*node = ft_lstnew(s);

	if (!node)
		return (perror("malloc error"), 1);
	int ret = (!node->content || !(!strcmp(s, node->content)));
	if (ret)
		printf(STRF(FT(char *))": "ERROR"\n");
	free(node);
	return (ret);
}

int	int_content(int *n)
{
	t_list	*node = ft_lstnew(n);

	if (!node)
		return (perror("malloc error"), 1);
	int ret = (!node->content || memcmp(n, node->content, sizeof(int)));
	if (ret)
		printf(STRF(FT(int *))": "ERROR"\n");
	free(node);
	return (ret);
}

int	main(void)
{
	int		err = 0;
	char	*empty = "";
	char	*s = "chabadabada";
	int		n = 1622;

	err += free_not_alloc(s);
	err += alloc_content(s);
	err += char_content(s);
	err += char_content(empty);
	err += int_content(&n);
	err += null_check();
	return (err != 0);
}
