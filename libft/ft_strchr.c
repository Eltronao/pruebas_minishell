/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <larraingonzalez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:59:20 by lagonzal          #+#    #+#             */
/*   Updated: 2023/05/31 13:59:36 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

char	*ft_strchr(const char *s, int c)
{
	int	n;

	if (!s)
		return (NULL);
	n = 0;
	while (s[n] != (char)c && s[n] != '\0')
		n++;
	if (s[n] == (char)c)
		return ((char *)&s[n]);
	else
		return (NULL);
}

/*int	main(void)
{
	const char	s[] = "teste";
	int	c = '.';
	printf("%s\n", s);
	printf("%s\n", ft_strchr(s, 't' + 256));
	return (0);	
}*/
