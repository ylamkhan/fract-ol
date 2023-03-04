/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 23:55:40 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/03/05 00:03:41 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_data	*ft_init(t_data *t)
{
	t->minre = -2.0;
	t->maxre = 2.0;
	t->minim = -2.0;
	t->maxim = 2;
	t->col_or = 10;
	t->zoom = 1;
	return (t);
}

void	ft_update_image(t_data *t)
{
	t = ft_init(t);
	t->mlx = mlx_init();
	t->mlx_wind = mlx_new_window(t->mlx, WIDTH, HEIGH, "mandelbrot");
	t->img = mlx_new_image(t->mlx, WIDTH, HEIGH);
	t->addr = mlx_get_data_addr(t->img, &t->bits_per_pixel, &t->line_length,
			&t->endian);
	mlx_hook(t->mlx_wind, 2, 0, key_hook, t);
	mlx_hook(t->mlx_wind, 17, 0, ft_close, t);
	mlx_mouse_hook(t->mlx_wind, mouse_hook1, t);
	mandelbrot(t);
	mlx_loop(t->mlx);
}

void	ft_update_image2(t_data *t)
{
	t = ft_init(t);
	t->mlx = mlx_init();
	t->mlx_wind = mlx_new_window(t->mlx, WIDTH, HEIGH, "julia");
	t->img = mlx_new_image(t->mlx, WIDTH, HEIGH);
	t->addr = mlx_get_data_addr(t->img, &t->bits_per_pixel, &t->line_length,
			&t->endian);
	mlx_hook(t->mlx_wind, 2, 0, key_hook2, t);
	mlx_mouse_hook(t->mlx_wind, mouse_hook2, t);
	mlx_hook(t->mlx_wind, 17, 0, ft_close, t);
	mlx_hook(t->mlx_wind, 6, 0, mouse_move2, t);
	julia(t, 0.285, 0.0013);
	mlx_loop(t->mlx);
}

int	main(int ac, char **av)
{
	t_data	*t;

	(void)ac;
	t = malloc(sizeof(t_data));
	if (!t)
		return (0);
	if (!ft_strncmp(av[1], "mandelbrot", 10))
		ft_update_image(t);
	else if (!ft_strncmp(av[1], "julia", 5))
		ft_update_image2(t);
	else if (!ft_strncmp(av[1], "puissance_3", 22))
		ft_update_image3(t);
	else
		help();
}
