/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <lagonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:03:31 by lagonzal          #+#    #+#             */
/*   Updated: 2022/12/23 13:33:19 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putptr_n(unsigned long long nbr, const char *base, int *n)
{
	if (*n == 0)
		*n += write(1, "0x", 2);
	if (nbr >= 16)
		ft_putptr_n(nbr / 16, base, n);
	*n += ft_putchar_n(base[nbr % 16]);
}
