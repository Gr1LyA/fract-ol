/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MONDELBROT.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 20:13:04 by tharland          #+#    #+#             */
/*   Updated: 2021/11/22 20:13:05 by tharland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_mandelbrot(t_vars *vars, t_complex *delta)
{
	int	x;
	int	y;

	delta->re = 3.0 / (WIDTH * vars->size);
	delta->im = 2.0 / (HEIGHT * vars->size);
	vars->re_min = vars->x_cord;
	vars->im_max = vars->y_cord;
	x = vars->x;
	y = vars->y;
	while (x != 0)
	{
		vars->re_min -= delta->re;
		x--;
	}
	while (y != 0)
	{
		vars->im_max += delta->im;
		y--;
	}
}

void	sub_mondelbrot(t_complex *z, t_complex *c, t_vars *vars, int *i)
{
	while (*i < (50 + 50 * vars->iter))
	{
		square(z);
		summ(z, c);
		modul(z);
		if (z->modul > 2)
			break ;
		(*i)++;
	}
}

void	color_mandelbrot(t_data *img, t_vars *vars, t_pixel pixel, int i)
{
	int	color;

	if (vars->color_flag == 1)
		color = 0x702a42;
	if (vars->color_flag == 2)
		color = 0xffffff;
	if (i == 50 + 50 * vars->iter && vars->color_flag == 0)
		my_mlx_pixel_put(img, pixel.x, pixel.y, 0xffffff);
	else if (i < 50 + 50 * vars->iter && vars->color_flag == 0 && i > 15)
		my_mlx_pixel_put(img, pixel.x, pixel.y, 0xffffff + i * 50);
	if (i == 50 + 50 * vars->iter && vars->color_flag != 0)
		my_mlx_pixel_put(img, pixel.x, pixel.y, color);
	else if (vars->color_flag != 0)
		my_mlx_pixel_put(img, pixel.x, pixel.y, color + i * 300 * i);
}

void	mondelbrot_img(t_vars *vars, t_data *img)
{
	t_pixel		pixel;
	t_complex	z;
	t_complex	c;
	int			i;

	pixel.x = 0;
	zoom_mandelbrot(vars, &(vars->delta));
	while (pixel.x < WIDTH)
	{
		c.re = vars->re_min + (vars->delta).re * pixel.x;
		pixel.y = 0;
		while (pixel.y < HEIGHT)
		{
			c.im = vars->im_max - (vars->delta).im * pixel.y;
			z.re = 0;
			z.im = 0;
			i = 0;
			sub_mondelbrot(&z, &c, vars, &i);
			color_mandelbrot(img, vars, pixel, i);
			(pixel.y)++;
		}
		(pixel.x)++;
	}
}

int	image_MD(t_vars *vars)
{
	t_data	img;

	img.img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.b_per_p, &img.length, &img.end);
	mondelbrot_img(vars, &img);
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
	return (0);
}
