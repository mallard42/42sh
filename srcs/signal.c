/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <ltran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 11:54:37 by mallard           #+#    #+#             */
/*   Updated: 2018/05/04 01:02:57 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../twenty.h"

void	sig_int(int sig)
{
	int		status;
	int		i;

	i = -1;
	while (++i < g_kill)
		wait(0);
	status = 0;
	while (g_ed->rpz[0] == 0)
		g_ed = g_ed->next;
	if (g_ed->rpz[0] == 1 && g_ed->rpz[1] != 1)
		return ;
	waitpid(-1, &status, 0);
	if (WIFSIGNALED(status) && WEXITSTATUS(status) == 0)
		write(1, "\n", 1);
	else
	{
		write(1, "\r", 1);
		init();
		free_list(&g_env);
		tputs(tgetstr("ce", NULL), 0, ft_put);
		free_for_exit(NULL, 0);
		exit(0);
	}
	sig = 0;
}

void	sig_int3(int sig)
{
	sig = 0;
	while (g_ed->rpz[0] == 0)
		g_ed = g_ed->next;
	if (g_ed->rpz[0] == 1 && g_ed->rpz[1] != 1)
		return ;
	g_fz->mode[3] = 0;
	add_his(&g_hs, NULL, g_fz);
	write(1, "\n", 1);
	init_for_new(&g_hs, &g_fz, &g_ed);
}

void	sig_int_here_2(void)
{
	while (g_ed->rpz[0] == 0)
		g_ed = g_ed->next;
	if (g_ed->rpz[0] == 1 && g_ed->rpz[1] != 1)
		return ;
	while (g_fz->here->prev != NULL)
		g_fz->here = g_fz->here->prev;
	if (g_fz->here->next == NULL)
		exit(0);
	while (g_fz->here->prev != NULL)
		g_fz->here = g_fz->here->prev;
	while (g_fz->here->ok[0] == 1)
		g_fz->here = g_fz->here->next;
	g_fz->here->ok[0] = 1;
}

void	sig_int_here(int sig)
{
	sig_int_here_2();
	sig = open("/tmp/in", O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (g_fz->here->doc && g_fz->here->doc != NULL)
		ft_putendl_fd(g_fz->here->doc, sig);
	close(sig);
	while (g_fz->here->prev != NULL)
		g_fz->here = g_fz->here->prev;
	if (check_struct(g_fz) == 0)
	{
		cursor_end(g_ed);
		g_env = treat_cmd_here(g_env, &g_ed, &g_hs, &g_fz);
		g_fz->mode[3] = check_struct(g_fz);
		init_for_new(&g_hs, &g_fz, &g_ed);
		init_data(&g_fz);
	}
}

void	ls_signal(int i)
{
	if (i == 6)
	{
		signal(SIGINT, sig_int_here);
		signal(SIGCHLD, SIG_DFL);
	}
	else if (i != 0)
	{
		signal(SIGINT, sig_int3);
		signal(SIGCHLD, SIG_DFL);
	}
	else
	{
		signal(SIGINT, sig_int);
		signal(SIGCHLD, SIG_DFL);
	}
}
