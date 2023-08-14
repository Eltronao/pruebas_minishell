/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:34:57 by lagonzal          #+#    #+#             */
/*   Updated: 2022/09/13 15:28:14 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdio.h>
#include<string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	n;

	n = 0;
	while (n < len)
	{
		((unsigned char *)b)[n] = c;
		n++;
	}
	return (b);
}

/*int	main(void)
{
	char str[] = "HHHHHHHHHH";
	printf("%s\n", str);

	memset(str, '$', 3);
	printf("%s\n", str);
	char str2[] = "HHHHHHHHHH";
	printf("%s\n", str2);

	ft_memset(str, '$', 3);
	printf("%s\n", str);
	return (0);
}*/
