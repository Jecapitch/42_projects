/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 23:34:51 by jpiscice          #+#    #+#             */
/*   Updated: 2025/04/14 00:03:33 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	argc_check(int argc);
static void	argparse(int argc, char **argv, t_data *data);
static void	print_arglist1(void);
static void	print_arglist2(void);

static void	print_arglist1(void)
{
	ft_fprintf(STDERR, BHRED"/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\" \
		"/!\\/!\\/!\\/!\\/!\\"CRESET"\n" \
		"Missing argument (-_-)\n" \
		"./fractol fractal_type [max_iterations] [n]" \
		"[\"c_x c_y div_x div_y\"]\n" \
		"          [\"r g b\"] [zoom]\n" \
		"\n" \
		"Use d or \"\" for default.\n" \
		"> fractal_type (char): "BHRED"m"CRESET"andelbrot " \
		BHRED"j"CRESET"ulia "BHRED"c"CRESET"haos_game " \
		BHRED"s"CRESET"ierpinski_triangle\n" \
		"> max_iterations (int): 0-%d.\n" \
		"                        Default: - %d for "MANDEL" set,\n" \
		"                                 - %d for "JULIA" set,\n" \
		"                                 - %d for "SIERP" & "CHAOS".\n", \
		ITERMAX, MITERDEF, JITERDEF, SITERDEF);
}

static void	print_arglist2(void)
{
	ft_fprintf(STDERR, \
	"> n (int): exponent in "JULIA" & "MANDEL" sets (z^n + c). Default: %d.\n" \
	"           Number of vertices in "CHAOS". Default: %d\n" \
	"           Ignored in "SIERP".\n" \
	"> c_x, c_y, div_x, div_y (int): in "JULIA" set (z^n + c),\n" \
	"                                c = c_x / div_x + (y / div_y)i.\n" \
	"                                Default: - %d %d 100 100 for "JULIA".\n" \
	"                                         - %d %d 1 1 for "SIERP", \n" \
	"                                           other values resulting\n"\
	"                                           in a lovely chaos effect.\n" \
	"                                         - in "CHAOS", c = jump = " \
												"n / (n + 3).\n" \
	"                                Ignored for "MANDEL".\n" \
	"> r, g, b (int): factors for color range. "\
	"                 Default: - %d %d %d for "JULIA" and "MANDEL".\n" \
	"                          - %d %d %d for "CHAOS" and "SIERP".\n" \
	"> zoom (long): initial zoom factor. Default: %d.\n" \
	"               Ignored for "SIERP" and "CHAOS".\n" \
	"\n", \
	N, NC, (int)(creal(JCDEF) * 100), (int)(cimag(JCDEF) * 100), \
	(int)(creal(SCDEF)), (int)(cimag(SCDEF)), RDEF, GDEF, BDEF, \
	CRDEF, CGDEF, CBDEF, ZOOM);
}

static void	argc_check(int argc)
{
	if (argc >= 2)
		return ;
	print_arglist1();
	print_arglist2();
	exit(EXIT_SUCCESS);
}

static void	argparse(int argc, char **argv, t_data *data)
{
	get_type(data, argv[1]);
	get_n(argc, argv, data);
	n_iter(argc, argv, data);
	c_val(argc, argv, data);
	rgb_init(argc, argv, data);
	zoom_init(argc, argv, data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	argc_check(argc);
	mlxcreate(&data);
	argparse(argc, argv, &data);
	init_data(&data);
	open_help(&data);
	srand(time(NULL));
	mlx_do_key_autorepeaton(data.mlx);
	print_data(data);
	ft_printf("fractal computed\n");
	mlx_hook(data.win, 4, 1L << 2, mousehook, &data);
	mlx_hook(data.win, 2, 1L << 0, keyhook, &data);
	mlx_hook(data.win, 17, 1L << 2, quit, &data);
	mlx_loop_hook(data.mlx, fractal, &data);
	mlx_loop(data.mlx);
}
