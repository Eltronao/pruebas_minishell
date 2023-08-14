/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:27:23 by lagonzal          #+#    #+#             */
/*   Updated: 2022/09/14 18:28:21 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include"libft.h"

char	*ft_strjoin(const char *s1, char const *s2)
{
	int		t_len;
	char	*s3;
	size_t	n;
	size_t	m;

	if (!s1)
		return (ft_strdup(s2));
	n = 0;
	m = 0;
	t_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	s3 = malloc(t_len * sizeof(char));
	if (!s3)
		return (NULL);
	while (s1[m] != '\0')
		s3[n++] = s1[m++];
	m = 0;
	while (s2[m] != '\0')
		s3[n++] = s2[m++];
	s3[n] = '\0';
	return (s3);
}

/*int	main(void)
{
	const char	s1[] = "Hola ";
	const char	s2[] = "mundo!";
	char		*s3;
	printf("s1 + s2 = %s%s\n",s1, s2);
	s3 = ft_strjoin(s1, s2);
	printf("s3 = %s\n",s3);
	free(s3);
	return (0);
}*/
