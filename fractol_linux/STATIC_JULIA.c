/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   STATIC_JULIA.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 20:13:20 by tharland          #+#    #+#             */
/*   Updated: 2021/11/22 20:13:21 by tharland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_stat_img(t_vars *vars, t_data *img)
{
	t_pixel		pixel;
	int			i;
	t_complex	z;
	t_complex	c;

	pixel.x = 0;
	zoom_julia(vars, &(vars->delta));
	while (pixel.x < WIDTH_JULIA)
	{
		c.re = vars->x_stat;
		pixel.y = 0;
		while (pixel.y < HEIGHT)
		{
			c.im = vars->y_stat;
			z.re = vars->re_min + pixel.x * (vars->delta).re;
			z.im = vars->im_max - pixel.y * (vars->delta).im;
			i = 0;
			sub_julia(&z, &c, vars, &i);
			color_julia(img, vars, pixel, i);
			(pixel.y)++;
		}
		(pixel.x)++;
	}
}

void	Julia_stat(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->color_flag = 0;
	init_julia(vars);
	if (vars->x_stat > 2 || vars->x_stat < -2)
		message2();
	if (vars->y_stat > 2 || vars->y_stat < -2)
		message2();
	vars->win = mlx_new_window(vars->mlx, WIDTH_JULIA, HEIGHT, "JULIA");
	mlx_hook(vars->win, 2, 0, key_hook, vars);
	mlx_hook(vars->win, 17, 0, close_win, vars);
	mlx_mouse_hook(vars->win, mouse_hook, vars);
	mlx_loop_hook(vars->mlx, image_JS, vars);
	mlx_loop(vars->mlx);
}

int	image_JS(t_vars *vars)
{
	t_data	img;

	img.img = mlx_new_image(vars->mlx, WIDTH_JULIA, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.b_per_p, &img.length, &img.end);
	julia_stat_img(vars, &img);
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
	return (0);
}
