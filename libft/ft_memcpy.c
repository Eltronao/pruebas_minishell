/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:38:29 by lagonzal          #+#    #+#             */
/*   Updated: 2022/09/05 14:40:49 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<string.h>
#include<stdio.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	m;

	m = 0;
	if (src == NULL && dst == NULL)
		return (dst);
	while (m < n)
	{
		((unsigned char *)dst)[m] = ((unsigned char *)src)[m];
		m++;
	}
	return (dst);
}

/*{
	size_t	m;

	m = 0;
		while (((unsigned char *)src)[m] != '\0' && m < n - 1)
		{	
			((unsigned char *)dst)[m] = ((unsigned char *)src)[m];
			m++;
		}
		((unsigned char *)dst)[m] = ((unsigned char *)src)[m];
	return (dst);
}*/

/*int	main(void)
{
	char src[] = "";
	char src2[] = "";
	char dst[] = "";
	char dst2[] = "";
	printf("%s\n", src);
	printf("%s\n", dst);
	memcpy(NULL, NULL, 2);
	printf("%s\n", src);
	printf("%s\n", dst);
	printf("%s\n", src2);
	printf("%s\n", dst2);
	ft_memcpy(NULL, NULL, 2);
	printf("%s\n", src);
	printf("%s\n", dst);
	return (0);
}*/
