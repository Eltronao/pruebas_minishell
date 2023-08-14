/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:02:47 by lagonzal          #+#    #+#             */
/*   Updated: 2022/09/04 20:01:25 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<string.h>
#include<stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	m;

	m = 0;
	while (n > m)
	{	
		if (((unsigned char *)s1)[m] != ((unsigned char *)s2)[m])
			return (((unsigned char *)s1)[m] - ((unsigned char *)s2)[m]);
		m++;
	}
	return (0);
}
	/*{
	size_t m;
	int	a;
	int	b;

	m = 0;
	if (((char *)s1)[m] == ((char *)s2)[m] && ((char *)s1)[m] == '\0')
		return(-1);
	while (m < n - 1 && ((char *)s1)[m] && ((char *)s2)[m])
	{	
		if (((unsigned char *)s1)[m] != ((unsigned char *)s2)[m])
		{
			a = ((int *)s1)[m];
			b = ((int *)s2)[m];
			if (a > b)
				return(1);
			if (a < b)
				return(-1);
		}
		m++;
	}
	return(0);
}*/

/*int	main(void)
{
	const char	s1[] = "";
	const char	s2[] = "";
	printf("%s\n", s1);
	printf("%s\n", s2);
	printf("%d\n", memcmp(s1, s2, 7));
	printf("%d\n", ft_memcmp(s1, s2, 7));
	return (0);
}*/
