/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 23:55:58 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/03/04 23:58:42 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main_madelbrot(t_data *t, int x, int y)
{
	double	a;
	double	b;
	double	z_r;
	double	z_i;
	double	tmp;

	t->re_fract = (t->maxre - t->minre) / WIDTH;
	t->im_fract = (t->maxim - t->minim) / HEIGH;
	a = t->minre + x * t->re_fract;
	b = (t->maxim - y * t->im_fract);
	z_r = a;
	z_i = b;
	t->iteration = -1;
	while (++t->iteration <= 60)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + a;
		z_i = 2 * tmp * z_i + b;
		if (z_r * z_r + z_i * z_i > 4)
		{
			my_mlx_pixel_put(t, x, y, t->iteration * t->iteration * t->col_or);
			break ;
		}
	}
	return (t->iteration);
}

void	mandelbrot(t_data *t)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGH)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if (main_madelbrot(t, x, y) == 61)
				my_mlx_pixel_put(t, x, y, 0x000000FF);
		}
	}
	mlx_put_image_to_window(t->mlx, t->mlx_wind, t->img, 0, 0);
}
