/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <lagonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:09:45 by lagonzal          #+#    #+#             */
/*   Updated: 2022/12/23 13:42:48 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_n(long long int nbr, const char *base, int *n)
{
	int	bl;

	bl = ft_strlen(base);
	if (nbr < 0)
	{
		nbr = nbr * -1;
		*n += ft_putchar_n('-');
	}
	if (nbr >= bl)
		ft_putnbr_n(nbr / bl, base, n);
	*n += ft_putchar_n(base[nbr % bl]);
}
