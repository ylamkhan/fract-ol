/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 23:55:13 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/03/04 23:55:16 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main_julia(t_data *t, int tab[2], double tab1[2])
{
	double	a;
	double	b;
	double	z_r;
	double	z_i;
	double	tmp;

	a = t->minre + tab[0] * t->re_fract;
	b = t->maxim - tab[1] * t->im_fract;
	z_r = a;
	z_i = b;
	t->iteration = -1;
	while (++t->iteration <= 60)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + tab1[0];
		z_i = 2 * tmp * z_i + tab1[1];
		if (z_r * z_r + z_i * z_i > 4)
		{
			my_mlx_pixel_put(t, tab[0], tab[1], t->iteration * t->iteration
				* t->col_or);
			break ;
		}
	}
	return (t->iteration);
}

void	julia(t_data *t, double re, double im)
{
	int		tab[2];
	double	tab1[2];

	tab1[0] = re;
	tab1[1] = im;
	t->re_fract = (t->maxre - t->minre) / (WIDTH - 1);
	t->im_fract = (t->maxim - t->minim) / (HEIGH - 1);
	tab[1] = -1;
	while (++(tab[1]) < HEIGH)
	{
		tab[0] = -1;
		while (++(tab[0]) < WIDTH)
		{
			if (main_julia(t, tab, tab1) == 61)
				my_mlx_pixel_put(t, tab[0], tab[1], 0x000000FF);
		}
	}
	mlx_put_image_to_window(t->mlx, t->mlx_wind, t->img, 0, 0);
}
