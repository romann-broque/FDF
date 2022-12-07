/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:04:04 by rbroque           #+#    #+#             */
/*   Updated: 2022/12/07 19:01:02 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_lst_pos(t_list *lst)
{
	while (lst != NULL)
	{
		printf("[%d %d %d]", ((t_pos *)lst->content)->x,
							((t_pos *)lst->content)->y,
							((t_pos *)lst->content)->z);
		if (lst->next)
			printf("-");
		lst = lst->next;
	}
	printf("\n");
}

void	add_coord_to_lst(t_list **lst, char **coord, int y, int zoom)
{
	t_list	*curr_pos;
	int		i;
	int		x;

	i = 0;
	x = 0;
	while (coord[i] != NULL)
	{
		curr_pos = ft_lstnew(init_pos(x + HEIGHT / 4, y * zoom + WIDTH / 4, ft_atoi(coord[i])));
		ft_lstadd_back(lst, curr_pos);
		x += zoom;
		++i;
	}
}

t_list	*get_pos(int fd, int zoom)
{
	t_list	*pos_lst;
	int		y;
	char	**coord;
	char	*curr_line;

	y = 0;
	pos_lst = NULL;
	curr_line = get_next_line(fd);
	while (curr_line != NULL)
	{
		coord = ft_split_set(curr_line, " \n");
		add_coord_to_lst(&pos_lst, coord, y, zoom);
		free_array((void **)coord);
		curr_line = get_next_line(fd);
		++y;
	}
//	print_lst_pos(pos_lst);
	return (pos_lst);
}
