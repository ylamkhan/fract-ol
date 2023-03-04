/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 23:54:09 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/03/04 23:54:17 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIDTH 800.0
# define HEIGH 800.0
# define DX 0.01
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	void	*mlx;
	void	*mlx_wind;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		iteration;
	double	minre;
	double	maxre;
	double	minim;
	double	maxim;
	double	re_fract;
	double	im_fract;
	int		col_or;
	double	zoom;
	double	c_i;
	double	c_r;
}			t_data;

void		mandelbrot(t_data *t);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_data		*ft_init(t_data *t);
int			main_julia(t_data *t, int tab[2], double tab1[2]);
void		julia(t_data *t, double re, double im);
int			ft_strncmp(char *s1, char *s2, size_t n);
void		ft_update_image(t_data *t);
void		ft_update_image2(t_data *t);
void		keyhook_min(int keycode, t_data *fr);
int			key_hook2(int keycode, t_data *fr);
int			key_hook(int keycode, t_data *fr);
int			zooom_in1(int button, int x, int y, t_data *fr);
int			zooom_in2(int button, int x, int y, t_data *fr);
int			mouse_hook2(int button, int x, int y, t_data *fr);
int			mouse_move2(int x, int y, t_data *fr);
int			mouse_hook1(int button, int x, int y, t_data *fr);
int			ft_close(void);
int			main_madelbrot_puissance_3(t_data *t, int x, int y);
void		mandelbrot_puissance_3(t_data *t);
void		ft_update_image3(t_data *t);
int			key_hook3(int keycode, t_data *fr);
int			zooom_in3(int button, int x, int y, t_data *fr);
int			mouse_hook3(int button, int x, int y, t_data *fr);
void		help(void);
#endif
