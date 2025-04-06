/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 23:34:51 by jpiscice          #+#    #+#             */
/*   Updated: 2025/04/06 04:51:28 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	argc_check(int argc);

static void	argc_check(int argc)
{
	if (argc < 2)
	{
		ft_fprintf(2, \
				BHRED"/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\" \
				"/!\\/!\\/!\\/!\\/!\\"CRESET"\n" \
				"Missing argument (-_-):" \
				"\n" \
				"./fractol fractal_type [max_iterations] " \
				"[\"c_x c_y div_x div_y\"] [zoom]" \
				"\n" \
				"\n" \
				"Use \"\" for default." \
				"\n" \
				"> fractal_type (char): "BHRED"m"CRESET"andelbrot " \
				BHRED"j"CRESET"ulia" \
				"\n" \
				"> max_iterations (int): 0-1000. Default is %d." \
				"\n" \
				"> c_x, c_y, div_x, div_y (int): for Julia set with formula "\
				"z^2 + c, c = c_x / div_x + (y / div_y)i." \
				"\n" \
				"> zoom (int): initial zoom factor. Default is %d." \
				"\n\n", ITERDEF, ZOOM);
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	argc_check(argc);
	mlxcreate(&data);
	argparse(argc, argv, &data);
	open_help(&data);
	init_data(&data);
	mlx_do_key_autorepeaton(data.mlx);
	mlx_put_image_to_window(data.mlx, data.win, data.curr_img->img, 0, 0);
	print_data(data);
	julia(data);
	ft_printf("fractal computed\n");
	mlx_hook(data.win, 4, 1L << 2, mousehook, &data);
	mlx_hook(data.win, 2, 1L << 0, keyhook, &data);
	mlx_hook(data.win, 17, 1L << 2, quit, &data);
	mlx_loop_hook(data.mlx, julia, &data);
	mlx_loop(data.mlx);
}
