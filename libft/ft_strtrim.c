/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:00:16 by lagonzal          #+#    #+#             */
/*   Updated: 2022/09/21 16:53:03 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>
#include"libft.h"

int	ft_chrstr(char c, const char *set)
{
	size_t	n;

	n = 0;
	while (set[n] != '\0')
	{
		if (set[n] == c)
			return (1);
		n++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*ptr;
	size_t	n;
	size_t	len;
	size_t	m;

	n = 0;
	m = 0;
	while (s1[n] != '\0' && ft_chrstr(s1[n], set) == 1)
		n++;
	len = ft_strlen(s1);
	while (n < len && ft_chrstr(s1[len - 1], set))
		len--;
	ptr = malloc((len - n + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (n < len)
		ptr[m++] = s1[n++];
	ptr[m] = '\0';
	return (ptr);
}

/*int	main(void)
{
	char	s1[] = "ABCDEFGFEIDCBA";
	char	set[] ="CDI";
	char	*s2;
	printf("teniendo el string %s queremos borrar los caracteres %s\n", s1, set);
	s2 = ft_strtrim(s1, set);
	printf("despues del borrado queda asi%s\n", s2);
	free(s2);
	return(0);
}*/
