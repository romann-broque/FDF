/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 02:11:43 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/28 02:28:38 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_PARSER_H

// is_valid_parsing.c

bool	is_parsing_valid(char ***parsing);

// parser.c

void	parse(char ****dest, const char *path_file);

// read.c

bool	is_valid_file(char **content);
char	**get_file_content(const char *path_file, const size_t size);
size_t	get_file_size(const char *path_file);
void	free_parsing(char ****parsing);

// parser_utils.c

bool	is_color_prefix_valid(const char *format);
bool	is_format_valid(const char *str);

#endif
