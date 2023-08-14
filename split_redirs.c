/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_redirs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <lagonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:50:59 by lagonzal          #+#    #+#             */
/*   Updated: 2023/08/14 19:21:05 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_name_s(char *s)
{
	int	n;

	n = 0;
	while (s[n] == '>' || s[n] == '<')
		n++;
	return (find_name(&s[n]));
}

char	*find_name(char *s)
{
	int	n;

	n = 0;
	while (s[n])
	{
		
		n++;
	}
}

char **split_redirs(char **s)
{
	int		n;
	int		m;
	char	*holder;

	n = 0;
	while (s[n])
	{
		m = 0;
		while (s[n][m])
		{
			if (s[n][m] == '<' || s[n][m] == '>')
			{
				if (s[n][m + 1] == '\0' || s[n][m + 2] == '\0')
					holder = find_name(s[++n]);
				else
					holder = find_name_s(&s[n][m]);
			}	
		}
	}
}

int main(void)
{
	// char *s[] = {"<Es>to", "es", ">una|redireccion", "prueba<<patata", NULL};
	char **s;
	s = malloc(5 * sizeof(char *));
	s[0] = ft_strdup("<Es>to");
	s[1] = ft_strdup("es");
	s[2] = ft_strdup(">una|redireccion");
	s[3] = ft_strdup("prueba<<patata");
	s[4] = NULL;
	s = split_redirs(s);
	ft_double_print(s);
	ft_double_free(s);
}
