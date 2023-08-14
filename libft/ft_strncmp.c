/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <lagonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:57:29 by lagonzal          #+#    #+#             */
/*   Updated: 2022/12/29 10:11:18 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	m;
	size_t	j;

	m = 0;
	j = 0;
	if (n == 0)
		return (0);
	if (s1[j] == '+')
		j++;
	if (s2[m] == '+')
	{
		m++;
		n++;
	}
	while ((unsigned char) s1[j] == (unsigned char) s2[m]
		&& s1[j] && s2[m] && m < n - 1)
	{
		j++;
		m++;
	}
	return (((unsigned char *)s1)[j] -((unsigned char *)s2)[m]);
}

/*int	main(void)
{
	const char	s1[] = "Hola que tal?";
	const char s2[] = "Hola qUe tAl?";

	printf("%d\n", ft_strncmp(s1, s2, 7));
}*/
