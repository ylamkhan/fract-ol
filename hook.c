/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 23:54:52 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/03/05 00:09:20 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	keyhook_min(int keycode, t_data *fr)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 124 || keycode == 2)
	{
		fr->minre -= DX;
		fr->maxre -= DX;
	}
	else if (keycode == 125 || keycode == 1)
	{
		fr->maxim += DX;
		fr->minim += DX;
	}
	else if (keycode == 123 || keycode == 0)
	{
		fr->minre += DX;
		fr->maxre += DX;
	}
}

int	key_hook2(int keycode, t_data *fr)
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
	julia(fr, fr->c_r, fr->c_i);
	return (0);
}

int	zooom_in2(int button, int x, int y, t_data *fr)
{
	double	mouse_pos[2];
	double	s;

	(void)button;
	mouse_pos[0] = ((x / WIDTH) * (fr->maxre - fr->minre)) + fr->minre;
	mouse_pos[1] = ((-y / HEIGH) * (fr->maxim - fr->minim)) + fr->maxim;
	fr->c_r = mouse_pos[0];
	fr->c_i = mouse_pos[1];
	fr->zoom = 2;
	s = (fr->maxre - fr->minre) * fr->zoom;
	fr->maxre = mouse_pos[0] + (fr->maxre - mouse_pos[0]) * fr->zoom;
	fr->minre = fr->maxre - s;
	fr->maxim = mouse_pos[1] + (fr->maxim - mouse_pos[1]) * fr->zoom;
	fr->minim = fr->maxim - s;
	julia(fr, fr->c_r, fr->c_i);
	return (0);
}

int	mouse_hook2(int button, int x, int y, t_data *fr)
{
	double	mouse_pos[2];
	double	s;

	mouse_pos[0] = ((x / WIDTH) * (fr->maxre - fr->minre)) + fr->minre;
	mouse_pos[1] = ((-y / HEIGH) * (fr->maxim - fr->minim)) + fr->maxim;
	fr->c_r = mouse_pos[0];
	fr->c_i = mouse_pos[1];
	if (button == 5)
	{
		fr->zoom = 0.5;
		s = (fr->maxre - fr->minre) * fr->zoom;
		fr->maxre = mouse_pos[0] + (fr->maxre - mouse_pos[0]) * fr->zoom;
		fr->minre = fr->maxre - s;
		fr->maxim = mouse_pos[1] + (fr->maxim - mouse_pos[1]) * fr->zoom;
		fr->minim = fr->maxim - s;
		julia(fr, fr->c_r, fr->c_i);
	}
	else if (button == 4)
		zooom_in2(button, x, y, fr);
	return (0);
}

int	mouse_move2(int x, int y, t_data *fr)
{
	fr->re_fract = (fr->maxre - fr->minre) / WIDTH;
	fr->im_fract = (fr->maxim - fr->minim) / HEIGH;
	fr->c_i = (fr->maxim - (double)y * fr->im_fract);
	fr->c_r = ((double)x * fr->re_fract + fr->minre);
	julia(fr, fr->c_r, fr->c_i);
	return (0);
}
