/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_tests.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:18:47 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/06 21:05:57 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUN_TESTS_H
# define RUN_TESTS_H

# include "../includes/fdf.h"

//////////////
/// PARSER ///
//////////////

int		parser_test(const char *path_file);
bool	is_same_parsing(const char ***pars1, const char ***pars2);

#endif
