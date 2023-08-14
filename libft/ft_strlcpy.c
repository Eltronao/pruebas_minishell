/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:03:49 by lagonzal          #+#    #+#             */
/*   Updated: 2022/09/04 20:09:27 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include<stdio.h>
#include<string.h>*/

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	n;

	n = 0;
	if (dstsize > 0)
	{
		while (n < dstsize - 1 && src[n] != '\0')
		{
			dst[n] = src[n];
			n++;
		}
		dst[n] = '\0';
		while (src[n] != '\0')
			n++;
		return (n);
	}
	else
		return (n = ft_strlen(src));
}

/*int	main(void)
{
	const char src1[] = "123456789";
	const char src2[] = "123456789";
	char dest1[6];
	char dest2[6];
	int num1;
	int num2;
	printf("%s\n", src1);
	num1 = strlcpy(dest1, src1, 6);
	printf("%d\n", num1);
	printf("%s\n", dest1);
	printf("%s\n", src1);
	num2 = ft_strlcpy(dest2, src2, 6);
	printf("%d\n", num2);
	printf("%s\n", dest2);
	return (0);
}*/
