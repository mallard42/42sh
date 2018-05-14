/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 13:30:17 by mallard           #+#    #+#             */
/*   Updated: 2018/05/03 13:30:18 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_isspace(char const *s, unsigned int i)
{
	if (s[i] == '\n' || s[i] == ' ' || s[i] == '\t' || s[i] == 'v' \
		|| s[i] == 's')
		return (0);
	return (1);
}
