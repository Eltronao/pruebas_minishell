/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_second_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <lagonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 11:40:27 by lagonzal          #+#    #+#             */
/*   Updated: 2023/08/14 14:03:51 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minishell.h"
#include <stdio.h>

char **spliter(char *s, int m)
{
	char	**holder;

	holder = malloc(4 * sizeof(char *));
	holder[3] = NULL;
	holder[0] = ft_substr(s, 0, m);
	holder[1] = ft_substr(s, m, 1);
	holder[2] = ft_substr(s, m + 1, ft_strlen(&s[m] + 1));
	free(s);
	return (holder);
}

char	**ft_resize2(char **sp, char **addition, int pos)
{
	int	n;
	int	m;
	char **new;

	n = 0;
	while (sp[n])
		n++;
	m = 0;
	while (addition[m])
		m++;
	new = malloc((m + n) * sizeof(char *));
	n = -1;
	while (++n < pos)
		new[n] = sp[n];
	m = 0;
	while (addition[m])
		new[n++] = addition[m++];
	
	while (sp[++pos])
	{
		new[n] = sp[pos];
		n++;
	}
	new[n] = NULL;
	return (free(sp), free(addition), new);
}

char	**ft_split_pipes(char **sp)
{
	int		n;
	int		m;
	char	**holder;

	n = 0;
	while (sp[n])
	{
		m = -1;
		while (sp[n] && sp[n][++m])
		{
			if (sp[n][m] == '\'' && (m == 0 || sp[n][m - 1] != 97))
				m += find_quoute_end(&sp[n][m]);
			else if (sp[n][m] == '\"' && (m == 0 || sp[n][m - 1] != 97))
				m += find_d_quoute_end(&sp[n][m]);
			if (sp[n][m] == '|')
			{
				holder = spliter(sp[n], m);
				sp = ft_resize2(sp, holder, n);
				m = 0;
				n++;
			}
		}
		n++;
	}
	return (sp);
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
	s = ft_split_pipes(s);
	
	ft_double_print(s);
	ft_double_free(s);
}
