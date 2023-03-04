/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_fractol_puissances_3.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:04:30 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/03/04 22:19:55 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_update_image3(t_data *t)
{
	t = ft_init(t);
	t->mlx = mlx_init();
	t->mlx_wind = mlx_new_window(t->mlx, WIDTH,
			HEIGH, "mandelbrot_puissance_3");
	t->img = mlx_new_image(t->mlx, WIDTH, HEIGH);
	t->addr = mlx_get_data_addr(t->img, &t->bits_per_pixel, &t->line_length,
			&t->endian);
	mlx_hook(t->mlx_wind, 2, 0, key_hook3, t);
	mlx_mouse_hook(t->mlx_wind, mouse_hook3, t);
	mlx_hook(t->mlx_wind, 17, 0, ft_close, t);
	mandelbrot_puissance_3(t);
}

int	main_madelbrot_puissance_3(t_data *t, int x, int y)
{
	double	a;
	double	b;
	double	z_r;
	double	z_i;
	double	tmp;

	t->re_fract = (t->maxre - t->minre) / (WIDTH - 1);
	t->im_fract = (t->maxim - t->minim) / (HEIGH - 1);
	a = t->minre + x * t->re_fract;
	b = t->maxim - y * t->im_fract;
	z_r = a;
	z_i = b;
	t->iteration = -1;
	while (++t->iteration <= 60)
	{
		tmp = z_r;
		z_r = z_r * z_r * z_r - 3 * z_i * z_i * z_r + a;
		z_i = 3 * z_r * z_r * z_i - z_i * z_i * z_i + b;
		if (z_r * z_r + z_i * z_i > 4)
		{
			my_mlx_pixel_put(t, x, y, t->iteration * t->iteration * t->col_or);
			break ;
		}
	}
	return (t->iteration);
}

void	mandelbrot_puissance_3(t_data *t)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGH)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if (main_madelbrot_puissance_3(t, x, y) == 61)
				my_mlx_pixel_put(t, x, y, 0x000000FF);
		}
	}
	mlx_put_image_to_window(t->mlx, t->mlx_wind, t->img, 0, 0);
	mlx_loop(t->mlx);
}
