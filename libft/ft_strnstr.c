/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:43:23 by lagonzal          #+#    #+#             */
/*   Updated: 2022/09/22 15:39:47 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n;
	size_t	m;

	n = 0;
	m = 0;
	if (!needle[m])
		return (&((char *)haystack)[n]);
	if (len <= 0)
		return (NULL);
	while (haystack[n] && needle[m] && n < len)
	{
		m = 0;
		while (haystack[n + m] == needle[m] && len - n > ft_strlen(needle) - 1)
		{
			m++;
			if (needle[m] == '\0')
				return (&((char *)haystack)[n]);
		}
	n++;
	}
	return (NULL);
}
