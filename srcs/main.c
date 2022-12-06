/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:22:16 by rbroque           #+#    #+#             */
/*   Updated: 2022/12/06 19:32:33 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_pos(t_pos *pos, int x, int y)
{
	pos->x = x;
	pos->y = y;
}

t_pos	*init_pos(int x, int y)
{
	t_pos	*new;

	new = (t_pos *)malloc(sizeof(t_pos));
	if (new != NULL)
		set_pos(new, x, y);
	return (new);
}

int	main(int ac, char **av)
{
	t_win	*window;
	int		height = HEIGHT;
	int		width = WIDTH;

	if (ac > 1)
		height = atoi(av[1]); // change atoi->ft_atoi
	if (ac > 2)
		width = atoi(av[2]); // change atoi->ft_atoi
	window = init_window(height, width, "Nice");
//	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, window->data->img, 0, 0);
	loop(window);
	destroy_window(window);
	return (0);
}
