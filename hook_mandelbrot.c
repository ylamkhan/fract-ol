/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 23:54:38 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/03/05 00:01:57 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, t_data *fr)
{
	keyhook_min(keycode, fr);
	if (keycode == 126 || keycode == 13)
	{
		fr->minim -= DX;
		fr->maxim -= DX;
	}
	else if (keycode == 15)
		fr->col_or = 0x3e9c41;
	else if (keycode == 16)
		fr->col_or = 0x7b3e9c;
	else if (keycode == 17)
		fr->col_or = 0x403e9c;
	mandelbrot(fr);
	return (0);
}

int	zooom_in1(int button, int x, int y, t_data *fr)
{
	double	mouse_pos[2];
	double	s;

	(void)button;
	mouse_pos[0] = ((x / WIDTH) * (fr->maxre - fr->minre)) + fr->minre;
	mouse_pos[1] = ((-y / HEIGH) * (fr->maxim - fr->minim)) + fr->maxim;
	fr->zoom = 2;
	s = (fr->maxre - fr->minre) * fr->zoom;
	fr->maxre = mouse_pos[0] + (fr->maxre - mouse_pos[0]) * fr->zoom;
	fr->minre = fr->maxre - s;
	fr->maxim = mouse_pos[1] + (fr->maxim - mouse_pos[1]) * fr->zoom;
	fr->minim = fr->maxim - s;
	mandelbrot(fr);
	return (0);
}

int	mouse_hook1(int button, int x, int y, t_data *fr)
{
	float	mouse_pos[2];
	float	s;

	mouse_pos[0] = ((x / WIDTH) * (fr->maxre - fr->minre)) + fr->minre;
	mouse_pos[1] = ((-y / HEIGH) * (fr->maxim - fr->minim)) + fr->maxim;
	if (button == 5)
	{
		fr->zoom = 0.5;
		s = (fr->maxre - fr->minre) * fr->zoom;
		fr->maxre = mouse_pos[0] + (fr->maxre - mouse_pos[0]) * fr->zoom;
		fr->minre = fr->maxre - s;
		fr->maxim = mouse_pos[1] + (fr->maxim - mouse_pos[1]) * fr->zoom;
		fr->minim = fr->maxim - s;
		mandelbrot(fr);
	}
	else if (button == 4)
		zooom_in1(button, x, y, fr);
	return (0);
}

int	ft_close(void)
{
	exit(0);
}
