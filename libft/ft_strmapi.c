/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:40:55 by lagonzal          #+#    #+#             */
/*   Updated: 2022/09/15 19:51:21 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*ptr;
	size_t	m;
	size_t	n;

	n = ft_strlen(s);
	ptr = malloc((n + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	m = 0;
	while (s[m] != '\0')
	{
		ptr[m] = s[m];
		m++;
	}
	ptr[m] = '\0';
	m = 0;
	while (ptr[m] != '\0')
	{
		ptr[m] = (*f)(m, ptr[m]);
		m++;
	}
	return (ptr);
}
