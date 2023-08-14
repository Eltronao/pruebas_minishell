/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_space.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <lagonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:14:45 by lagonzal          #+#    #+#             */
/*   Updated: 2023/08/09 17:51:25 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_find_space(const char *s)
{
	int	n;

	if (!s)
		return (NULL);
	n = 0;
	while (s[n] != '\0')
	{
		if (ft_is_space(s[n]))
			return ((char *)&s[n]);
		n++;
	}
	return ((char *)&s[n]);
}
