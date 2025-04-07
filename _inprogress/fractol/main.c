/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 23:34:51 by jpiscice          #+#    #+#             */
/*   Updated: 2025/04/07 03:25:02 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	argc_check(int argc);

static void	argc_check(int argc)
{
	if (argc >= 2)
		return ;
	ft_fprintf(2, BHRED"/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\" \
						"/!\\/!\\/!\\/!\\/!\\"CRESET"\n"ARGLIST \
		"> fractal_type (char): "BHRED"m"CRESET"andelbrot " \
		BHRED"j"CRESET"ulia "BHRED"s"CRESET"ierpinski\n" \
		"> max_iterations (int): 0-%d.\n" \
		"                        Default is %d for "MANDEL" set,\n" \
		"                                   %d for "JULIA" set,\n" \
		"                                   %d for "SIERP" triangle.\n" \
		"> exponent (int): value of n in "JULIA" & "MANDEL" sets (z^n + c).\n" \
		"> c_x, c_y, div_x, div_y (int): in "JULIA" set (z^n + c),\n" \
		"                                c = c_x / div_x + (y / div_y)i.\n" \
		"                                Ignored for other types.\n" \
		"> factor1, factor2, factor3 (int): factors for color range.\n" \
		"                                   Default is 1942 42 19.\n" \
		"> zoom (int): initial zoom factor.\n" \
		"              Default is %d.\n" \
		"              Ignored for "SIERP".\n" \
		"\n", \
		ITERMAX, MITERDEF, JITERDEF, SITERDEF, ZOOM);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data	data;

	argc_check(argc);
	mlxcreate(&data);
	argparse(argc, argv, &data);
	init_data(&data);
	open_help(&data);
	mlx_do_key_autorepeaton(data.mlx);
	print_data(data);
	ft_printf("fractal computed\n");
	mlx_hook(data.win, 4, 1L << 2, mousehook, &data);
	mlx_hook(data.win, 2, 1L << 0, keyhook, &data);
	mlx_hook(data.win, 17, 1L << 2, quit, &data);
	mlx_loop_hook(data.mlx, fractal, &data);
	mlx_loop(data.mlx);
}
