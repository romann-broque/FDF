/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:44:38 by rbroque           #+#    #+#             */
/*   Updated: 2022/12/07 18:46:54 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_map(t_list *lst, t_data *img)
{
	t_pos	*pos;

	while (lst != NULL)
	{
		pos = lst->content;
		my_mlx_pixel_put(img, pos->x, pos->y, WHITE + pos->z);
		lst = lst->next;
	}
}
