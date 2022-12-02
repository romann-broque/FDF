/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:06:36 by rbroque           #+#    #+#             */
/*   Updated: 2022/11/14 10:00:11 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			new_len;
	size_t			slen;
	char			*substr;

	if (s == NULL)
		substr = NULL;
	else
	{
		slen = ft_strlen(s);
		new_len = 0;
		if (start <= slen)
			new_len = get_min(slen - start, len);
		else
			start = slen;
		substr = (char *)malloc((new_len + 1) * sizeof(char));
		if (substr != NULL)
			ft_strlcpy(substr, s + start, new_len + 1);
	}
	return (substr);
}
