/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lecartuy <lecartuy@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:49:54 by leo               #+#    #+#             */
/*   Updated: 2024/12/09 12:18:00 by lecartuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_format(const char format, va_list arg)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += ft_print_c(va_arg(arg, int));
	else if (format == 's')
		count += ft_print_s(va_arg(arg, char *));
	else if (format == 'd' || format == 'i')
		count += ft_print_d(va_arg(arg, int));
	else if (format == 'u')
		count += ft_print_u(va_arg(arg, unsigned int));
	else if (format == 'x' || format == 'X')
		count += ft_print_x(va_arg(arg, unsigned int), format);
	else if (format == 'p')
		count += ft_print_p(va_arg(arg, uintptr_t));
	else if (format == '%')
		count += ft_print_c('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
			count += ft_format(str[++i], args);
		else
			count += ft_print_c(str[i]);
		i++;
	}
	va_end(args);
	if (count < 0)
		return (-1);
	return (count);
}
