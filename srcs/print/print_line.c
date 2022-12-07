/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 03:28:54 by rbroque           #+#    #+#             */
/*   Updated: 2022/12/07 18:05:25 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	print_line_less(t_pos *pos1, t_pos *pos2, t_data *data, int color, int sign)
{
	int dx = sign * (pos2->x - pos1->x);
	int dy = pos2->y - pos1->y;
	int dp = 2 * dy - dx; /* Valeur initiale de dp */
	int deltaE = 2 * dy;
	int deltaNE = 2 * (dy - dx);
   	t_pos		*pos;

	pos = init_pos(pos1->x, pos1->y, pos1->z);
	while (pos->x < pos2->x)
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

static void	print_line_more(t_pos *pos1, t_pos *pos2, t_data *data, int color, int sign)
{
	int dx = sign * (pos2->x - pos1->x);
	int dy = pos2->y - pos1->y;
	int dp = 2 * dy - dx; /* Valeur initiale de dp */
	int deltaE = 2 * dx;
	int deltaNE = 2 * (dx - dy);
   	t_pos		*pos;

	pos = init_pos(pos1->x, pos1->y, pos1->z);
	while (pos->y != pos2->y)
	{
		if (sign * dp <= 0) /* On choisit le point E */
			dp += deltaE; /* Nouveau dp */
		else /* On choisit le point NE */
		{
			dp += deltaNE; /* Nouveau dp */
			if (pos->x < pos2->x)
				pos->x++; /* Calcul de y_p+1 */
		}
		pos->y += get_sign(dy); /* Calcul de x_p+1 */
		my_mlx_pixel_put(data, pos->x, pos->y, color);
	}
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
