/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:45:14 by lagonzal          #+#    #+#             */
/*   Updated: 2022/09/13 16:09:24 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	n;

	n = ft_strlen(s);
	while (s[n] != (char)c && n > 0)
		n--;
	if (n == 0 && s[n] != (char)c)
		return (NULL);
	else
		return ((char *)s + n);
}

/*int	main(void)
{
	const char	s[] = "https://www.google.es";
	int	c = '.';
	printf("%s\n", s);
	printf("%s\n", ft_strrchr(s, c));
	return (0);
}*/
