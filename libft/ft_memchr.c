/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:31:05 by lagonzal          #+#    #+#             */
/*   Updated: 2022/09/15 20:18:24 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>
#include<unistd.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	m;

	m = 0;
	if (n == 0)
		return (NULL);
	while (m < n - 1 && ((unsigned char *)s)[m] != (unsigned char)c)
		m++;
	if (((unsigned char *)s)[m] != (unsigned char)c)
		return (NULL);
	else
		return ((void *)s + m);
}

/*int	main(void)
{
	char	s[] = "/|\x12\xff\x09\x42\2002\42|\\";
	int		c = 2;

	char *s2 = memchr( "teste", 'z', 357489638736287765);
	char *s3 = ft_memchr(s,'z', 473867893459867289);
	printf("%s\n", s2);
	printf("%s\n", s3);
	}*/
