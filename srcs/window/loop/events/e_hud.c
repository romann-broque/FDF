/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_hud.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:14:08 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/25 12:15:26 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	toggle_hud(t_win *window)
{
	if (window->hud_status == ON)
		window->hud_status = OFF;
	else
		window->hud_status = ON;
	return (EXIT_SUCCESS);
}
