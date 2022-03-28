/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algebra.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 20:13:28 by tharland          #+#    #+#             */
/*   Updated: 2021/11/22 20:13:29 by tharland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_complex(t_complex *z, double x, double y)
{
	z->re = x;
	z->im = y;
}

void	modul(t_complex *z)
{
	z->modul = sqrt((z->re * z->re + z->im * z->im));
}

void	square(t_complex *z)
{
	double	previous_re;

	previous_re = z->re;
	z->re = z->re * z->re - z->im * z->im;
	z->im = 2 * previous_re * z->im;
}

void	cube(t_complex *z)
{
	double	previous_re;

	previous_re = z->re;
	z->re = pow(z->re, 3) - 3 * z->re * pow(z->im, 2);
	z->im = 3 * pow(previous_re, 2) * z->im - pow(z->im, 3);
}

void	summ(t_complex *z, t_complex *z1)
{
	z->re = z->re + z1->re;
	z->im = z->im + z1->im;
}

// int main()
// {
// 	t_complex	z;

// 	z.re = 2;
// 	z.im = 3;
// 	cube(&z);
// 	printf("%f, %f\n", z.re, z.im);
// 	return (0);
// }
