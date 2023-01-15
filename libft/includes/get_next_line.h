/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:00:22 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/15 17:15:38 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# define OPEN_MAX FOPEN_MAX

typedef enum e_line_status
{
	INVALID_LINE,
	VALID_LINE
}	t_line_status;

char	*get_next_line(int fd);

#endif
