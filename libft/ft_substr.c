/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:20:50 by lagonzal          #+#    #+#             */
/*   Updated: 2022/09/22 15:53:00 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	n;

	n = 0;
	substr = 0;
	if (ft_strlen(s) >= start)
	{
		if (len >= ft_strlen(&s[start]))
			n = ft_strlen(&s[start]);
		if (len < ft_strlen(&s[start]))
			n = len;
		substr = malloc(n + 1 * sizeof(char));
	}
	else if (ft_strlen(s) < start || len <= 1)
	{	
		return (ft_strdup(""));
	}
	if (!substr)
		return (NULL);
	if (ft_strlen(s) > start)
		ft_strlcpy(substr, &s[start], n + 1);
	else
		substr[0] = '\0';
	return (substr);
}

/*int	main(void)
{
	//const char d[] = "tripouille";
	char *str;
	str = ft_substr("hola", 0, 18446744073709551615);
	printf("%s\n", str);
	free(str);
	return (0);
}*/
