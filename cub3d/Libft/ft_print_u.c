/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lecartuy <lecartuy@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:51:55 by lecartuy          #+#    #+#             */
/*   Updated: 2024/12/09 12:33:12 by lecartuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_putunbr(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr >= 10)
	{
		count += ft_putunbr(nbr / 10);
		count += ft_putunbr(nbr % 10);
	}
	else
		count += ft_print_c(nbr + 48);
	return (count);
}

int	ft_print_u(unsigned int nbr)
{
	return (ft_putunbr(nbr));
}
