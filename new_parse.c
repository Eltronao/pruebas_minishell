/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <lagonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:15:41 by lagonzal          #+#    #+#             */
/*   Updated: 2023/08/14 19:31:17 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse(char *s);
t_cmnd	**create_cmnds(char **spltd);
t_cmnd	*cmnd_init(void);
void	get_cmnd(char **spltd, t_cmnd **head);
int		quoute_parse(char *s);
void	pipe_case(t_cmnd *new);

int	main(void)
{
	char	*s = "<<a echo afjioa | cat -e";
	parse(s);
	
}

void	parse(char *s)
{
	char	**spltd;
	t_cmnd	**head;

	if (quoute_parse(s))
		return (1);
	spltd = mini_split(s);
	if (!spltd)
		return (1);
	head = create_cmnds(spltd);
}
int	quoute_parse(char *s)
{
	int	n;
	int	searching;

	n = 0;
	searching = 0;
	while (s[n])
	{
		if (s[n] == '\"' && s[n - 1] != BACK_SLASH)
		{
			if (searching == 0)
				searching = 1;
			else if (searching == 1)
				searching = 0;
		}
		else if (s[n] == '\'')
		{
			if (searching == 0)
				searching = 2;
			else if (searching == 2)
				searching = 0;
		}
		n++;
	}
	return (searching);
}
t_cmnd	**create_cmnds(char **spltd)
{
	t_cmnd *head;

	head = NULL;
		get_cmnd(spltd, head);
}
t_cmnd	*cmnd_init(void)
{
	t_cmnd *new;

	new = malloc(sizeof(t_cmnd));
	new->cmd = NULL;
	new->i_r_type = NO_REDIR;
	new->o_r_type = NO_REDIR;
	new->i_fd = 0;
	new->i_fd = 1;
	new->i_limit = NULL;
	new->next = NULL;
	new->prev = NULL;
}
void	get_cmnd(char **spltd, t_cmnd **head)
{
	int		n;
	int		m;
	t_cmnd	*new;

	n = 0;
	m = 0;
	new = malloc (sizeof(t_cmnd));
	*head = new;
	while (spltd[n])
	{
		while (spltd[n][m])
		{
			if (spltd[n][m] == '|')
				pipe_case(new);
			/*else if (spltd[n][m] == '>' || spltd[n][m] == '<')
				redirection_case(spltd, new, n, m);
			else if (spltd[n][m] == '\"' || spltd[n][m] == '\'')*/
				
			else
				ft_resize(new->cmd, spltd[n]);
			m++;
		}
		n++;
	}
}
void	pipe_case(t_cmnd *prev)
{
	int	pipe_fd[2];
	t_cmnd	*next;

	pipe(pipe_fd);
	if (prev->o_r_type == NO_REDIR)
	{
		prev->o_r_type = PIPE_REDIR;
		prev->o_fd = pipe_fd[0];
	}
	next = cmnd_init;
	next->i_r_type = PIPE_REDIR;
	next->i_fd = pipe_fd[1];
}