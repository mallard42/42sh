/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 11:56:40 by mallard           #+#    #+#             */
/*   Updated: 2018/05/03 11:56:41 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../twenty.h"

t_edit	*touch(t_edit **ed, t_froz **fz, t_his **hs, t_env *env)
{
	if ((*fz)->buf[1] == 0 && (*fz)->buf[2] == 0)
	{
		if ((*fz)->buf[0] > 0 && (*fz)->buf[0] < 27)
			ctrl_touch(&(*ed), &(*fz), (*fz)->buf[0], env);
		else if ((*fz)->buf[0] == 127)
		{
			while ((*ed)->rpz[2] == 0)
				*ed = (*ed)->next;
			if ((*ed)->rpz[0] != 1)
			{
				*ed = erase_ed(*ed);
				(*fz)->nb[0] = (*fz)->nb[0] - 1;
				if ((*ed)->rpz[0] == 1 && (*ed)->rpz[1] == 1 &&
					(*ed)->rpz[2] == 3)
					(*fz)->mode[2] = 1;
			}
		}
		else
			*ed = add_ed(*ed, (*fz)->buf[0], NULL, &(*fz));
	}
	else
		*ed = extern_touch(*ed, &(*fz), &(*hs));
	print_shell(*ed, *fz);
	return (*ed);
}

t_edit	*extern_touch(t_edit *ed, t_froz **fz, t_his **hs)
{
	while (ed->rpz[2] == 0)
		ed = ed->next;
	if ((*fz)->buf[0] == 27 && (*fz)->buf[1] == 91 && ((*fz)->buf[2] == 72
		|| (*fz)->buf[2] == 70))
		ed = home_end(ed, *fz);
	else if ((*fz)->buf[0] == 27 && (*fz)->buf[1] == 91 && ((*fz)->buf[2] == 68
		|| (*fz)->buf[2] == 67))
		ed = left_right(ed, *fz);
	else if (*hs && (*fz)->mode[2] > 0 && (*fz)->buf[0] == 27 &&
		(*fz)->buf[1] == 91 && ((*fz)->buf[2] == 65 || (*fz)->buf[2] == 66))
		*hs = histo(*hs, (*fz)->buf[2], &ed, &(*fz));
	return (ed);
}

t_edit	*giv_position(t_edit *ed, int i)
{
	while (ed->rpz[0] == 0)
		ed = ed->next;
	while (ed->rpz[1] == 0)
	{
		if (ed->prev->c[0] == '\n' && i % g_nb->tb[0] != 0)
		{
			i = (((i / g_nb->tb[0]) + 1) * g_nb->tb[0]) + 1;
			ed->rpz[3] = i;
		}
		else
			ed->rpz[3] = i;
		++i;
		ed = ed->next;
	}
	if (ed->prev->c[0] == '\n' && i % g_nb->tb[0] != 0)
	{
		i = (((i / g_nb->tb[0]) + 1) * g_nb->tb[0]) + 1;
		ed->rpz[3] = i;
	}
	else
		ed->rpz[3] = i;
	return (ed);
}

t_edit	*left_right(t_edit *ed, t_froz *fz)
{
	if (fz->buf[2] == 68 && ed->rpz[0] == 0)
	{
		if (fz->mode[0] == 1 || fz->mode[1] == 1)
		{
			if (ed->rpz[4] == 1 && ed->prev->rpz[4] == 0)
				ed->prev->rpz[4] = 1;
			else
				ed->rpz[4] = 0;
		}
		ed->prev->rpz[2] = ed->rpz[2] - 1;
		ed->rpz[2] = 0;
	}
	else if (fz->buf[2] == 67 && ed->next->rpz[0] == 0)
	{
		if (fz->mode[0] == 1 || fz->mode[1] == 1)
		{
			if (ed->rpz[4] == 1 && ed->next->rpz[4] == 0)
				ed->next->rpz[4] = 1;
			else
				ed->rpz[4] = 0;
		}
		ed->next->rpz[2] = ed->rpz[2] + 1;
		ed->rpz[2] = 0;
	}
	return (ed);
}
