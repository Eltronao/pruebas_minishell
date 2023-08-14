/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:17:00 by lagonzal          #+#    #+#             */
/*   Updated: 2022/09/15 20:16:34 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

size_t	ft_numlen(int n)
{
	size_t	i;

	i = 1;
	if (n < 0)
		i++;
	while (n >= 10 || n <= -10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_nb2str(char **s, int n, size_t *i)
{
	while (*i >= 1 && s[0][*i] != '+' && s[0][*i] != '-')
	{
		if (n >= 10)
		{	
			*i = *i - 1;
			s[0][*i] = (n % 10) + '0';
			*s = ft_nb2str(s, n / 10, i);
		}
		else
		{	
			*i = *i - 1;
			s[0][*i] = n + '0';
			*i = 0;
			return (*s);
		}
	}
	return (*s);
}

char	*ft_minv(char *s)
{
	char	*ptr;

	ptr = ft_strdup(s);
	return (ptr);
}

char	*ft_itoa(int n)
{
	char	*s;
	size_t	i;
	int		sign;

	if (n == (-2147483647 - 1))
	{
		s = ft_minv("-2147483648");
		return (s);
	}	
	sign = 1;
	i = ft_numlen(n);
	if (n < 0)
	{		
		n = n * -1;
		sign = -1;
	}
	s = malloc ((i + 1) * sizeof(char));
	if (!s)
		return (NULL);
	if (sign < 0)
		s[0] = '-';
	s[i] = '\0';
	s = ft_nb2str(&s, n, &i);
	return (s);
}

/*int	main(void)
{
	int	n;
	char	*s;
	n = 0;
	s = ft_itoa(n);
	printf("%s\n", s);
	free(s);
	return (0);
}*/
