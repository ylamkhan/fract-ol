/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 23:55:28 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/03/04 23:55:33 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	if (!s1)
		return (1);
	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	help(void)
{
	write(1, "***************************************************\n", 52);
	write(1, "* please choose an argument from the given list : *\n", 52);
	write(1, "*             mandelbrot                          *\n", 52);
	write(1, "*             julia                               *\n", 52);
	write(1, "*             puissance_3                         *\n", 52);
	write(1, "***************************************************\n", 52);
}
