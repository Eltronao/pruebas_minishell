/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:53:22 by lagonzal          #+#    #+#             */
/*   Updated: 2022/09/02 17:53:31 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<string.h>
#include<stdio.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	m;

	m = 0;
	while (m < n)
	{
		((unsigned char *)s)[m] = 0;
		m++;
	}
}

/*int	main(void)
{
	char	*str;
	int	n;
	n = 0;
	str[0] = 4;
	str[1] = 5;
	str[2] = 6;
	bzero(str, 2);
	while (n < 3)
	{
		printf("%d\n", str[n]);
		n++;
	}
	return (0);
}*/
