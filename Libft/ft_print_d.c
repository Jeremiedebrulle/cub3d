/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lecartuy <lecartuy@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:51:47 by lecartuy          #+#    #+#             */
/*   Updated: 2024/12/09 12:18:23 by lecartuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putnbr(int nbr)
{
	int	count;

	count = 0;
	if (nbr == -2147483648)
		count += ft_print_s("-2147483648");
	else if (nbr < 0)
	{
		count += ft_print_c('-');
		nbr = -nbr;
		count += ft_putnbr(nbr);
	}
	else
	{
		if (nbr >= 10)
		{
			count += ft_putnbr(nbr / 10);
			count += ft_putnbr(nbr % 10);
		}
		else
			count += ft_print_c(nbr + 48);
	}
	if (count < 0)
		return (-1);
	return (count);
}

int	ft_print_d(int nbr)
{
	int	count;

	count = 0;
	count += ft_putnbr(nbr);
	if (count < 0)
		return (-1);
	return (count);
}
