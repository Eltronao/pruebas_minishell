/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <lagonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:42:44 by larra             #+#    #+#             */
/*   Updated: 2023/08/09 18:06:02 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_double_print(char **ptr)
{
	int	n;

	n = 0;
	while (ptr && ptr[n])
	{
		ft_printf("%s\n", ptr[n]);
		n++;
	}
}
