/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstdelone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:48:45 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/26 23:00:03 by jepiscic         ###   ########.fr       */
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
			t_lst	*node = tester_ft_lstnew(NULL);
			FT((t_list *)node, free);
			exit(1);
		}
		default:
		{
			int	status;
			wait(&status);
			if (WIFSIGNALED(status))
				return (printf(STRF(FT(NULL, free))": "ERROR"\n"), 1);
			return (0);
		}
	}
}

void	delstr(void *s)
{
	tester_ft_bzero(s, strlen((char *)s));
}

int	not_alloc_content(char *s)
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
			int	devnull = open("/dev/null", O_WRONLY);

			if (devnull != -1)
			{
				dup2(devnull, STDERR_FILENO);
				close(devnull);
			}
			t_lst	*node = tester_ft_lstnew(s);
			FT((t_list *)node, delstr);
			exit(0);
		}
		default:
		{
			int	status;
			int	ret = 0;
			wait(&status);
			if (WIFSIGNALED(status))
			{
				ret = 1;
				printf(STRF(FT(s, delstr))": "RED"Free when shouldn't\n"CRESET);
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
			int	devnull = open("/dev/null", O_WRONLY);

			if (devnull != -1)
			{
				dup2(devnull, STDERR_FILENO);
				close(devnull);
			}
			t_lst	*node = tester_ft_lstnew(strdup(s));
			char	*tmp = node->content;
			FT((t_list *)node, free);
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
				printf(STRF(FT(s, free))": "RED"Doesn't free when should\n"CRESET);
				ret = 1;
			}
			return (ret);
		}
	}
}

int	main(void)
{
	int		err = 0;
	char	s[] = "Tchou tchou !";

	err += not_alloc_content(s);
	err += alloc_content(s);
	err += null_check();
	return (err != 0);
}
