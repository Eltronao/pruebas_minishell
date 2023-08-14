/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <lagonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:01:03 by lagonzal          #+#    #+#             */
/*   Updated: 2023/08/14 13:56:08 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*===============================REDIRECTIONS=================================*/ 
# define NO_REDIR 0
# define PIPE_REDIR 1
# define SIMPLE_REDIR 2
# define DOUBLE_REDIR 3
# define BACK_SLASH 92

#include "libft/libft.h"

typedef struct s_cmnd
{
	char			**cmd;
	int				i_r_type;
	int				o_r_type;
	int				i_fd;
	int				o_fd;
	char			*i_limit;
	struct s_cmnd	*next;
	struct s_cmnd	*prev;
}	t_cmnd;

char	**mini_split(char *s);
int	find_d_quoute_end(char *trimed);
int	find_quoute_end(char *trimed);

#endif
