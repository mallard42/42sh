/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 11:54:02 by mallard           #+#    #+#             */
/*   Updated: 2018/05/03 11:54:02 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../twenty.h"

void	put_prompt_init(t_froz **fz)
{
	put_prompt(*fz);
	if ((*fz)->mode[3] == 0)
		(*fz)->nb[0] = 3;
	else if ((*fz)->mode[3] == 1)
		(*fz)->nb[0] = 7;
	else if ((*fz)->mode[3] == 2)
		(*fz)->nb[0] = 8;
	else if ((*fz)->mode[3] == 3)
		(*fz)->nb[0] = 6;
	else if ((*fz)->mode[3] == 4)
		(*fz)->nb[0] = 8;
	else if ((*fz)->mode[3] == 5)
		(*fz)->nb[0] = 7;
	else if ((*fz)->mode[3] == 6)
		(*fz)->nb[0] = 9;
	else if ((*fz)->mode[3] == 20)
		(*fz)->nb[0] = 2;
}

void	put_prompt(t_froz *fz)
{
	if (fz->mode[3] == 0)
		ft_putstr("\033[0;33;40m>>\033[0m");
	else if (fz->mode[3] == 1)
		ft_putstr("\033[0;33;40mquote>\033[0m");
	else if (fz->mode[3] == 2)
		ft_putstr("\033[0;33;40mdquote>\033[0m");
	else if (fz->mode[3] == 3)
		ft_putstr("\033[0;33;40mpipe>\033[0m");
	else if (fz->mode[3] == 4)
		ft_putstr("\033[0;33;40mcmdand>\033[0m");
	else if (fz->mode[3] == 5)
		ft_putstr("\033[0;33;40mcmdor>\033[0m");
	else if (fz->mode[3] == 6)
		ft_putstr("\033[0;33;40mheredoc>\033[0m");
	else if (fz->mode[3] == 20)
		ft_putstr("\033[0;33;40m>\033[0m");
}

int		giv_last(t_froz *fz)
{
	if (fz->mode[3] == 0)
		return (3);
	else if (fz->mode[3] == 1)
		return (7);
	else if (fz->mode[3] == 2)
		return (8);
	else if (fz->mode[3] == 3)
		return (6);
	else if (fz->mode[3] == 4)
		return (8);
	else if (fz->mode[3] == 5)
		return (7);
	else if (fz->mode[3] == 6)
		return (9);
	else if (fz->mode[3] == 20)
		return (2);
	return (3);
}
