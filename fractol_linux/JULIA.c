/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   JULIA.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 20:12:44 by tharland          #+#    #+#             */
/*   Updated: 2021/11/22 20:12:47 by tharland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_julia(t_vars *vars, t_complex *delta)
{
	int	x;
	int	y;

	delta->re = 4.0 / (WIDTH_JULIA * vars->size);
	delta->im = 4.0 / (HEIGHT * vars->size);
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

void	sub_julia(t_complex *z, t_complex *c, t_vars *vars, int *i)
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

void	color_julia(t_data *img, t_vars *vars, t_pixel pixel, int i)
{
	int	color;

	if (vars->color_flag == 1)
		color = 0x702a42;
	if (vars->color_flag == 2)
		color = 0xffffff;
	if (i == 50 + 50 * vars->iter && vars->color_flag == 0)
		my_mlx_pixel_put(img, pixel.x, pixel.y, 0xffffff);
	else if (i < 50 + 50 * vars->iter && vars->color_flag == 0 && i > 10)
		my_mlx_pixel_put(img, pixel.x, pixel.y, 0xffffff + i * 50);
	if (i == 50 + 50 * vars->iter && vars->color_flag != 0)
		my_mlx_pixel_put(img, pixel.x, pixel.y, color);
	else if (vars->color_flag != 0)
		my_mlx_pixel_put(img, pixel.x, pixel.y, color + i * 300 * i);
}

void	julia_img(t_vars *vars, t_data *img)
{
	t_pixel		pixel;
	int			i;
	t_complex	z;
	t_complex	c;

	pixel.x = 0;
	zoom_julia(vars, &(vars->delta));
	mlx_mouse_get_pos(vars->mlx, vars->win, &(pixel.x_im), &(pixel.y_im));
	while (pixel.x < WIDTH_JULIA)
	{
		c.re = vars->re_min + pixel.x_im * (vars->delta).re;
		pixel.y = 0;
		while (pixel.y < HEIGHT)
		{
			c.im = vars->im_max - pixel.y_im * (vars->delta).im;
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

int	image_J(t_vars *vars)
{
	t_data	img;

	img.img = mlx_new_image(vars->mlx, WIDTH_JULIA, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.b_per_p, &img.length, &img.end);
	julia_img(vars, &img);
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
	return (0);
}
