/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lecartuy <lecartuy@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:51:57 by lecartuy          #+#    #+#             */
/*   Updated: 2024/12/09 12:17:44 by lecartuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_puthex(unsigned int nbr, char *chars)
{
	int	count;

	count = 0;
	if (nbr >= 16)
	{
		count += ft_puthex(nbr / 16, chars);
		count += ft_puthex(nbr % 16, chars);
	}
	else
		count += ft_print_c(chars[nbr]);
	return (count);
}

int	ft_print_x(unsigned int nbr, int format)
{
	char	*chars;

	if (format == 'x')
		chars = "0123456789abcdef";
	else
		chars = "0123456789ABCDEF";
	return (ft_puthex(nbr, chars));
}
