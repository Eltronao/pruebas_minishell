/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 13:53:52 by lagonzal          #+#    #+#             */
/*   Updated: 2022/09/15 20:12:21 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include <stdio.h>
#include<string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest;
	const char	*sorc;
	int			m;

	if (!dst && !src)
		return (NULL);
	dest = dst;
	sorc = src;
	if (dst < src)
	{	
		m = -1;
		while (len-- && ++m >= 0)
			dest[m] = sorc[m];
	}
	else
	{
		len--;
		while (len + 1)
		{
			dest[len] = sorc[len];
			len--;
		}
	}
	return (dst);
}
