/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lecartuy <lecartuy@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:51:50 by lecartuy          #+#    #+#             */
/*   Updated: 2024/12/09 12:17:02 by lecartuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_putptr(uintptr_t nbr)
{
	int		count;
	char	*chars;

	count = 0;
	chars = "0123456789abcdef";
	if (nbr >= 16)
	{
		count += ft_putptr(nbr / 16);
		count += ft_putptr(nbr % 16);
	}
	else
		count += ft_print_c(chars[nbr]);
	if (count < 0)
		return (-1);
	return (count);
}

int	ft_print_p(uintptr_t adr)
{
	int	count;

	count = 0;
	count += ft_print_s("0x");
	if (count < 0)
		return (-1);
	count += ft_putptr(adr);
	if (count < 0)
		return (-1);
	return (count);
}
