/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 20:13:53 by tharland          #+#    #+#             */
/*   Updated: 2021/11/22 20:13:54 by tharland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	sub_main(int argc, char **argv, t_vars *vars)
{
	char	*julia;
	char	*mondelbrot;
	char	*juliax3;

	juliax3 = "juliax3";
	julia = "julia";
	mondelbrot = "mandelbrot";
	if (ft_strcmp(argv[1], julia) == 0 && argc == 2)
		Julia(vars);
	else if (ft_strcmp(argv[1], julia) == 0 && argc == 4)
		Julia_stat(vars);
	else if (ft_strcmp(argv[1], mondelbrot) == 0)
		Mondelbrot(vars);
	else if (ft_strcmp(argv[1], juliax3) == 0)
		Juliax3(vars);
	else
		message();
	// Mondelbrot(vars);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc == 1)
		message();
	else if (argc == 4)
	{
		vars.x_stat = ft_atoi2(argv[2]) * 4.0 / WIDTH_JULIA - 2;
		vars.y_stat = ft_atoi2(argv[3]) * 4.0 / HEIGHT - 2;
	}
	if (argc == 2 || argc == 4)
		sub_main(argc, argv, &vars);
	else
		message();
	return (0);
}
