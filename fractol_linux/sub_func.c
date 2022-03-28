/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 20:14:02 by tharland          #+#    #+#             */
/*   Updated: 2021/11/22 20:14:04 by tharland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_win(int key)
{
	(void)key;
	exit (0);
	return (0);
}

void	message(void)
{
	printf("fractol mandelbrot\n");
	printf("fractol julia\n");
	printf("fractol julia x y\n");
	printf("fractol juliax3\n");
	exit (0);
}

void	message2(void)
{
	printf("x >= 0 && x <= %d\n", WIDTH_JULIA);
	printf("y >= 0 && x <= %d\n", HEIGHT);
	exit (0);
}

long int	sub_ft_atoi2(const char *str, long int res, int znak)
{
	int	i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	if (res * znak < -2147483648 || res * znak > 2147483647 || i == 0 || i > 11)
		message2();
	return (res * znak);
}

long int	ft_atoi2(const char *str)
{
	long int	res;
	int			znak;

	znak = 1;
	res = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		znak *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	return (sub_ft_atoi2(str, res, znak));
}
