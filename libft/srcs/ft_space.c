/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 13:33:55 by mallard           #+#    #+#             */
/*   Updated: 2018/05/03 13:33:57 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_space(char *s, int i)
{
	if (s[i] != '\n' || s[i] != ' ' || s[i] != '\t')
		return (1);
	return (0);
}
