/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:44:38 by rbroque           #+#    #+#             */
/*   Updated: 2022/12/07 19:20:32 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_map(t_list *lst, t_data *img)
{
	t_pos	*pos1;

	while (lst != NULL)
	{
		pos1 = lst->content;
		my_mlx_pixel_put(img, pos1->x, pos1->y, WHITE + pos1->z * BLUE);
		lst = lst->next;
	}
}
