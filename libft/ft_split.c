/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <larraingonzalez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:47:08 by lagonzal          #+#    #+#             */
/*   Updated: 2023/02/14 19:38:14 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wordcount(const char *s, char c)
{
	size_t	n;
	size_t	w;

	w = 0;
	n = 0;
	while (s[n] == c && s[n])
		n++;
	while (s[n] != '\0')
	{
		if (n == 0 && s[n] != c && s[n])
			w++;
		else if (s[n] && s[n - 1] == c && s[n] != c)
			w++;
		n++;
	}
	return (w);
}

char	**ft_double_free(char **s)
{
	int	n;

	n = -1;
	while (s[++n])
		free(s[n]);
	return (free(s), NULL);
}

char	**ft_copy(char ***ptr, const char *s, char c)
{
	size_t	n;
	size_t	m;
	size_t	i;

	n = 0;
	m = 0;
	i = 0;
	while (s[n] && ptr[0][m])
	{
		i = 0;
		while (s[n] == c)
			n++;
		while (s[n] == c)
			n++;
		while (s[n] != c && s[n] != '\0')
			ptr[0][m][i++] = s[n++];
		ptr[0][m][i] = '\0';
		m++;
	}
	return (*ptr);
}

char	**ft_split(const char *s, char c)
{
	int		len;
	int		w;
	char	**ptr;
	int		m;
	size_t	n;

	m = -1;
	n = 0;
	w = ft_wordcount(s, c);
	ptr = malloc ((w + 1) * sizeof(*ptr));
	if (!ptr)
		return (NULL);
	while (++m < w && w >= 1 && s[n] != '\0')
	{
		while (s[n] && s[n] == c)
			n++;
		len = 0;
		while (s[n] != c && s[n++] != '\0')
			len++;
		ptr[m] = malloc((len + 1) * sizeof(*ptr[m]));
		if (!ptr[m])
			return (ft_double_free(ptr));
	}
	ptr[m] = NULL;
	return (ft_copy(&ptr, s, c));
}
