/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 21:58:34 by rbroque           #+#    #+#             */
/*   Updated: 2022/12/06 19:03:21 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	windows_shap(t_data *img, int height, int width)
{
	int	x;
	int	y;

	x = 5;
	while (x < height / 4)
	{
		y = 5;
		while (y < width / 4)
		{
			my_mlx_pixel_put(img, height / 2 + x, width / 2 - y, GREEN);
			my_mlx_pixel_put(img, height / 2 - x, width / 2 - y, RED);
			my_mlx_pixel_put(img, height / 2 + x, width / 2 + y, YELLOW);
			my_mlx_pixel_put(img, height / 2 - x, width / 2 + y, BLUE);
			++y;
		}
		++x;
	}
}
void	print_ref(t_data *img, int height, int width)
{
	int	x;
	int	y;

	x = 0;
	while (x < height)
	{
		my_mlx_pixel_put(img, x, width / 2, WHITE);
		++x;
	}
	y = 0;
	while (y < width)
	{
		my_mlx_pixel_put(img, height / 2, y, WHITE);
		++y;
	}
}

int		get_sign(int nb)
{
	if (nb < 0)
		return (-1);
	return (1);
}

void	print_line_less(t_pos *pos1, t_pos *pos2, t_data *data, int color, int sign)
{
	int dx = sign * (pos2->x - pos1->x);
	int dy = pos2->y - pos1->y;
	int dp = 2 * dy - dx; /* Valeur initiale de dp */
	int deltaE = 2 * dy;
	int deltaNE = 2 * (dy - dx);
   	t_pos		*pos;

	pos = init_pos(pos1->x, pos1->y);
	while (pos->x <= pos2->x)
	{
		if (sign * dp <= 0) /* On choisit le point E */
			dp += deltaE; /* Nouveau dp */
		else /* On choisit le point NE */
		{
			dp += deltaNE; /* Nouveau dp */
			pos->y += get_sign(dy); /* Calcul de y_p+1 */
		}
		pos->x++; /* Calcul de x_p+1 */
		my_mlx_pixel_put(data, pos->x, pos->y, color);
	}
}

void	print_line_more(t_pos *pos1, t_pos *pos2, t_data *data, int color, int sign)
{
	int dx = sign * (pos2->x - pos1->x);
	int dy = pos2->y - pos1->y;
	int dp = 2 * dy - dx; /* Valeur initiale de dp */
	int deltaE = 2 * dx;
	int deltaNE = 2 * (dx - dy);
   	t_pos		*pos;

	pos = init_pos(pos1->x, pos1->y);
	while (pos->x <= pos2->x)
	{
		if (sign * dp <= 0) /* On choisit le point E */
			dp += deltaE; /* Nouveau dp */
		else /* On choisit le point NE */
		{
			dp += deltaNE; /* Nouveau dp */
			pos->x++; /* Calcul de y_p+1 */
		}
		pos->y += get_sign(dy); /* Calcul de x_p+1 */
		my_mlx_pixel_put(data, pos->x, pos->y, color);
	}
}

void	ft_swap(int *nb1, int *nb2)
{
	int	tmp;

	tmp = *nb1;
	*nb1 = *nb2;
	*nb2 = tmp;
}

void	print_line(t_pos *pos1, t_pos *pos2, t_data *data, int color)
{
	float	dx;
	float	dy;
	float	coeff;

	if (pos1->x > pos2->x)
	{
		ft_swap(&pos1->x, &pos2->x);
		ft_swap(&pos1->y, &pos2->y);
	}
	dx = pos2->x - pos1->x;
	dy = pos2->y - pos1->y;
	coeff = dy / dx;
	if (coeff >= 0)
	{
		if (coeff <= 1)
			print_line_less(pos1, pos2, data, color, 1);
		else
			print_line_more(pos1, pos2, data, color, 1);
	}
	else
	{
		if (coeff >= -1)
			print_line_less(pos1, pos2, data, color, -1);
		else
			print_line_more(pos1, pos2, data, color, -1);
	}
}
