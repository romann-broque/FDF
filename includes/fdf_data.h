/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_data.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 02:13:13 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/28 02:38:54 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_DATA_H

// free_data.c

void	free_data(const t_data *data, void *mlx_ptr);

// init_data.c

void	init_data(void *mlx_ptr, t_data *dest);

#endif
