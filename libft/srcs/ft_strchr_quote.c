/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_quote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 13:34:17 by mallard           #+#    #+#             */
/*   Updated: 2018/05/03 13:34:18 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int			ft_strchr_quote(const char *s, char c)
{
	int		i;
	char	*b;

	i = 0;
	b = (char*)s;
	while (b[i] && b[i] != c)
	{
		if (b[i] == '\\')
			i++;
		i += (b[i]) ? 1 : 0;
	}
	if (b[i] == c)
		return (i);
	return (i);
}