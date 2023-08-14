/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <lagonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:09:10 by lagonzal          #+#    #+#             */
/*   Updated: 2023/08/14 13:58:11 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minishell.h"
#include <stdio.h>

int		mini_wc(char *trimed);
void	separate(char *s, char **spltd, int n, int j);

int	find_quoute_end(char *trimed)
{
	int	n;

	n = 1;
	printf("simple quoute detected\n");
	while (trimed[n] && trimed[n] != '\'')
		n++;
	return (n);
}

int	find_d_quoute_end(char *trimed)
{
	int	n;

	n = 1;
	printf("double quoute detected\n");
	while (trimed[n] && trimed[n] != '\"')
	{
		n++;
		if (trimed[n] == '\"' && trimed[n - 1] == 92)
			n++;
	}
	return (n);
}

int	mini_wc(char *trimed)
{
	int		n;
	char	word;

	n = 0;
	word = 0;
	while (trimed[n])
	{
		if (trimed[n] != ' ' && (n == 0 || trimed[n - 1] == ' '))
			word++;
		if (trimed[n] == '\'' && (n == 0 || trimed[n - 1] != 92))
			n += find_quoute_end(&trimed[n]);
		else if (trimed[n] == '\"' && (n == 0 || trimed[n - 1] != 92))
			n += find_d_quoute_end(&trimed[n]);
		n++;
	}
	printf("%d malloc to do\n", word);
	return (word);
}

void	separate(char *s, char **spltd, int n, int j)
{
	int	start;
	int	end;

	start = 0;
	j = 0;
	while (s[start] && j < n)
	{
		if (ft_is_space(s[start]))
			start++;
		else if ((s[start] == '\'' || s[start] == '\"')
			&& (start == 0 || s[start - 1] != 92))
		{
			if (s[start] == '\'')
				end = start + find_quoute_end(&s[start]);
			else
				end = start + find_d_quoute_end(&s[start]);
			spltd[j++] = ft_substr(&s[start], 0, end - start + 1);
			start = end + 1;
		}
		else
		{
			spltd[j] = ft_substr(s, start, ft_find_space(&s[start]) - &s[start] + 1);
			start += ft_strlen(spltd[j++]);
		}
	}
}

char	**mini_split(char *s)
{
	char	**spltd;
	char	*trimed;
	int		n;

	trimed = ft_strtrim(s, " ");
	n = mini_wc(trimed);
	spltd = malloc((n + 1) * sizeof(char *));
	separate(s, spltd, n, 0);
	spltd[n] = NULL;
	printf("Words:\n=======================================================\n");
	ft_double_print(spltd);
	printf("=======================================================\n");
	free(trimed);
	ft_double_free(spltd);
	return (NULL);
}

/*int main(int argc, char **argv)
{
	char *s;
	
	s = argv[1];
	printf("String is :%s\n", s);
	mini_split(s);
}*/
