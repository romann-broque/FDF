/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:24:07 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/05 00:39:37 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <mlx.h>
# include <X.h>
# include <keysymdef.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define EXPECT_COUNT_ARG 2

/// PARSER ///

// read.c

bool	is_valid_file(char **content);
char	**get_file_content(const char *path_file, const size_t size);
size_t	get_file_size(const char *path_file);
void	free_parsing(char ***parsing);

// parser.c

char	***parse(const char *path_file);
bool	is_parsing_valid(char ***parsing);

#endif
