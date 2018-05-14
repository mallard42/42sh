/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ed.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 11:44:37 by mallard           #+#    #+#             */
/*   Updated: 2018/05/03 11:44:45 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../twenty.h"

void	modif_ed_nw(t_edit **ed, t_edit **nw)
{
	(*nw)->rpz[0] = 0;
	if ((*ed)->rpz[0] == 1)
	{
		(*ed)->rpz[0] = 0;
		(*nw)->rpz[0] = 1;
	}
	(*nw)->rpz[1] = 0;
	(*nw)->rpz[2] = 0;
	(*nw)->rpz[3] = (*ed)->rpz[3];
	(*nw)->rpz[4] = 0;
	(*ed)->rpz[3] = (*nw)->rpz[3] + 1;
	(*ed)->rpz[2] = (*ed)->rpz[2] + 1;
}

void	modif_edit(t_edit **ed, t_edit **nw)
{
	t_edit *tmp;

	tmp = *ed;
	modif_ed_nw(ed, nw);
	if (tmp->rpz[1] == 0 && tmp->rpz[3] >= tmp->next->rpz[3])
	{
		while (tmp->rpz[1] == 0)
		{
			tmp = tmp->next;
			if (tmp->prev->c[0] == '\n' && tmp->prev->rpz[3] % g_nb->tb[0] != 0)
				tmp->rpz[3] = (((tmp->prev->rpz[3] / g_nb->tb[0]) + 1)
					* g_nb->tb[0]) + 1;
			else
				tmp->rpz[3] = tmp->prev->rpz[3] + 1;
		}
		if (tmp->prev->c[0] == '\n' && tmp->prev->rpz[3] % g_nb->tb[0] != 0)
			tmp->rpz[3] = (((tmp->prev->rpz[3] / g_nb->tb[0]) + 1)
				* g_nb->tb[0]) + 1;
	}
}

t_edit	*add_ed(t_edit *ed, char c, t_edit *nw, t_froz **fz)
{
	if (!(nw = (t_edit*)malloc(sizeof(t_edit))))
		return (ed);
	while (ed->rpz[2] == 0)
		ed = ed->next;
	nw->c[0] = c;
	modif_edit(&ed, &nw);
	if (ed->rpz[0] == 1 && ed->rpz[1] == 1)
	{
		nw->next = ed;
		nw->prev = ed;
		ed->next = nw;
		ed->prev = nw;
	}
	else
	{
		nw->next = ed;
		nw->prev = ed->prev;
		ed->prev->next = nw;
		ed->prev = nw;
	}
	(*fz)->nb[0] = (*fz)->nb[0] + 1;
	return (nw);
}

t_edit	*init_edit(t_edit *init)
{
	if (!(init = (t_edit*)malloc(sizeof(t_edit))))
		return (NULL);
	init->c[0] = '\0';
	init->next = init;
	init->prev = init;
	init->rpz[0] = 1;
	init->rpz[1] = 1;
	init->rpz[2] = 3;
	init->rpz[3] = 3;
	init->rpz[4] = 0;
	return (init);
}

t_edit	*erase_ed(t_edit *ed)
{
	int		i;
	t_edit	*erase;

	while (ed->rpz[2] == 0)
		ed = ed->next;
	if (ed->rpz[0] == 1)
		return (ed);
	i = ed->prev->rpz[3];
	ed->rpz[2] = ed->rpz[2] - 1;
	ed->rpz[3] = i;
	erase = ed->prev;
	if (ed->prev->rpz[0] == 1)
		ed->rpz[0] = 1;
	ed->prev = ed->prev->prev;
	ed->prev->next = ed;
	while (ed->rpz[1] == 0)
	{
		ed = ed->next;
		ed->rpz[3] = ++i;
	}
	free(erase);
	return (ed);
}
