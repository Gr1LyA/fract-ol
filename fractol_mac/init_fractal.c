/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 20:13:44 by tharland          #+#    #+#             */
/*   Updated: 2021/11/22 20:13:46 by tharland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mondelbrot(t_vars *vars)
{
	vars->size = 1;
	vars->x = WIDTH / 2;
	vars->y = HEIGHT / 2;
	vars->x_cord = -0.5;
	vars->y_cord = 0;
	vars->re_min = -2.0;
	vars->im_max = 1.0;
	vars->iter = 0;
}

void	Mondelbrot(t_vars *vars)
{
	init_mondelbrot(vars);
	vars->color_flag = 0;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "MANDELBROT");
	mlx_hook(vars->win, 2, 0, key_hook, vars);
	mlx_hook(vars->win, 17, 0, close_win, vars);
	mlx_mouse_hook(vars->win, mouse_hook, vars);
	mlx_loop_hook(vars->mlx, image_MD, vars);
	mlx_loop(vars->mlx);
}

void	init_julia(t_vars *vars)
{
	vars->size = 1;
	vars->x = WIDTH_JULIA / 2;
	vars->y = HEIGHT / 2;
	vars->x_cord = 0;
	vars->y_cord = 0;
	vars->re_min = -2.0;
	vars->im_max = 2.0;
	vars->iter = 0;
}

void	Julia(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->color_flag = 0;
	init_julia(vars);
	vars->win = mlx_new_window(vars->mlx, WIDTH_JULIA, HEIGHT, "JULIA");
	mlx_hook(vars->win, 2, 0, key_hook, vars);
	mlx_hook(vars->win, 17, 0, close_win, vars);
	mlx_mouse_hook(vars->win, mouse_hook, vars);
	mlx_loop_hook(vars->mlx, image_J, vars);
	mlx_loop(vars->mlx);
}

void	Juliax3(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->color_flag = 0;
	init_julia(vars);
	vars->win = mlx_new_window(vars->mlx, WIDTH_JULIA, HEIGHT, "JULIA");
	mlx_hook(vars->win, 2, 0, key_hook, vars);
	mlx_hook(vars->win, 17, 0, close_win, vars);
	mlx_mouse_hook(vars->win, mouse_hook, vars);
	mlx_loop_hook(vars->mlx, image_Jx3, vars);
	mlx_loop(vars->mlx);
}
