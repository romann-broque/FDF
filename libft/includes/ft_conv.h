/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:06:20 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/17 12:54:51 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONV_H
# define FT_CONV_H

# define SPACE ' '
# define FIRST_WHITESPACE 9 
# define LAST_WHITESPACE 13

int		ft_atoi(const char *str);
int		ft_atoi_base(const char *str, char *base);
char	*ft_itoa(int n);

#endif