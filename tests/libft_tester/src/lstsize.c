/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstsize.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:48:45 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/27 14:53:31 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

int	null_check(void)
{
	switch(fork())
	{
		case -1:
		{
			fprintf(stderr, STRF(FT)": fork() error");
			exit(1);
		}
		case 0:
		{
			int	devnull = open("/dev/null", O_WRONLY);
			if (devnull != -1)
			{
				dup2(devnull, STDERR_FILENO);
				close(devnull);
			}
			t_list	*list = NULL;
			t_lst	*lst = NULL;
			int		ret = (FT(list) != STD(lst));
			tester_ft_lstclear(&lst, donothing);
			exit(ret);
		}
		default:
		{
			int	status;
			wait(&status);
			if (WIFSIGNALED(status))
				return (printf(STRF(FT)"(NULL): "YEL"crash (OK)"CRESET"\n"), 0);
			if (WEXITSTATUS(status))
				return (printf(STRF(FT)"(NULL): "ERROR"\n"), 1);
			return (0);
		}
	}
	return (0);
}

int	main(void)
{
	int		err = 0;
	char	*s[] = {"", "o", "mamma mia !", "fiouf pidoum \n$$wah", "\0argl"};
	int		tabsize = sizeof(s) / sizeof(char *);

	for (int i = 1; i <= tabsize; i++)
	{
		t_lst	*lst = tester_ft_lstcreate((void **)s, i);
		t_list	*list = (t_list *)lst;
		if (FT(list) != STD(lst))
		{
			err++;
			printf(STRF(FT)": "ERROR"\n");
		}
		tester_ft_lstclear(&lst, donothing);
	}
	err += null_check();
	return (err != 0);
}
