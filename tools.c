/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 20:14:09 by tharland          #+#    #+#             */
/*   Updated: 2021/11/22 20:14:10 by tharland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->length + x * (data->b_per_p / 8));
	*(unsigned int *)dst = color;
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
		close_window(vars);
	if (keycode == 18)
		vars->color_flag = 0;
	if (keycode == 19)
		vars->color_flag = 1;
	if (keycode == 20)
		vars->color_flag = 2;
	if (keycode == 69)
		vars->iter += 1;
	if (keycode == 78)
		vars->iter -= 1;
	if (keycode == 123)
		vars->x_cord -= (0.5 / vars->size);
	if (keycode == 124)
		vars->x_cord += (0.5 / vars->size);
	if (keycode == 126)
		vars->y_cord += (0.33 / vars->size);
	if (keycode == 125)
		vars->y_cord -= (0.33 / vars->size);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	if (button == 4 || button == 5)
	{
		vars->x_cord = x * (vars->delta).re + vars->re_min;
		vars->y_cord = vars->im_max - y * (vars->delta).im;
		vars->x = x;
		vars->y = y;
		if (button == 4)
			vars->size *= 2;
		if (button == 5)
			vars->size /= 2;
	}
	return (0);
}

int	ft_strcmp(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}
