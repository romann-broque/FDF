/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_tests.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:18:47 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/07 11:25:35 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUN_TESTS_H
# define RUN_TESTS_H

# include "../includes/fdf.h"

///////////////////////////////
//// <----- DEFINES -----> ////
///////////////////////////////

# define RESET "\033[0m"
# define RED "\033[1m\033[31m"
# define GREEN "\033[32m"
# define OK EXIT_SUCCESS
# define KO EXIT_FAILURE

///////////
// TITLE //
///////////

# define TEST_TITLE "\n<====== TESTS ======>\n"
# define PARSER_TEST_TITLE "\n-> PARSER\n\n"

///////////
// PATHS //
///////////

# define PARSER_PATH1 "./assets/parsing_test1.fdf"
# define PARSER_PATH2 "./assets/parsing_test2.fdf"
# define PARSER_PATH3 "./assets/parsing_test3.fdf"
# define PARSER_PATH4 "./assets/parsing_test4.fdf"
# define PARSER_PATH5 "./assets/parsing_test5.fdf"

/////////////////////////////////
//// <----- FUNCTIONS -----> ////
/////////////////////////////////

/// UTILS ///

int     check_result(const size_t test_index, const int curr_res, const int exp_res);
int     test_sequence(int (*tests[])(const size_t));
void    display_title(const char *title);

//////////////
/// PARSER ///
//////////////

int		parser_test(void);
bool	is_same_parsing(const char ***pars1, const char ***pars2);

#endif
