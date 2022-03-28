/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 20:13:36 by tharland          #+#    #+#             */
/*   Updated: 2021/11/22 20:13:38 by tharland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# define WIDTH_JULIA 800
# define WIDTH 1200
# define HEIGHT 800

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			b_per_p;
	int			length;
	int			end;
}				t_data;

typedef struct s_complex
{
	double		re;
	double		im;
	double		modul;
}				t_complex;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	int			x;
	int			y;
	double		x_cord;
	double		y_cord;
	double		re_min;
	double		im_max;
	double		size;
	t_complex	delta;
	int			iter;
	int			color_flag;
	double		y_stat;
	double		x_stat;
	// t_data		img;
}				t_vars;

typedef struct s_pixel
{
	int		x;
	int		y;
	int		x_im;
	int		y_im;
}				t_pixel;

int			key_hook(int keycode, t_vars *vars);
int			image_MD(t_vars *vars);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			mouse_hook(int button, int x, int y, t_vars *vars);
void		init_complex(t_complex *z, double x, double y);
void		modul(t_complex *z);
void		square(t_complex *z);
void		summ(t_complex *z, t_complex *z1);
void		julia_img(t_vars *vars, t_data *img);
int			image_J(t_vars *vars);
int			ft_strcmp(char *str1, char *str2);
void		init_mondelbrot(t_vars *vars);
void		message(void);
long int	ft_atoi2(const char *str);
int			image_JS(t_vars *vars);
void		zoom_julia(t_vars *vars, t_complex *delta);
void		sub_julia(t_complex *z, t_complex *c, t_vars *vars, int *i);
void		color_julia(t_data *img, t_vars *vars, t_pixel pixel, int i);
void		cube(t_complex *z);
void		init_mondelbrot(t_vars *vars);
void		Mondelbrot(t_vars *vars);
void		init_julia(t_vars *vars);
void		Julia_stat(t_vars *vars);
void		Julia(t_vars *vars);
void		Juliax3(t_vars *vars);
int			image_Jx3(t_vars *vars);
void		message2(void);
int			close_win(int key);

#endif
