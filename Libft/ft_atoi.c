/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lecartuy <lecartuy@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:52:13 by lecartuy          #+#    #+#             */
/*   Updated: 2024/10/17 11:29:33 by lecartuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				sign;
	unsigned long	result;

	sign = 1;
	result = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == 45)
	{
		sign *= -1;
		str++;
	}
	else if (*str == 43)
		str++;
	while (*str && (*str >= 48 && *str <= 57))
	{
		result *= 10;
		result += *str - '0';
		str++;
		if ((result > LONG_MAX) && (sign == 1))
			return (-1);
		else if ((result > LONG_MAX) && (sign == -1))
			return (0);
	}
	return (sign * result);
}

// #include <stdio.h>

// int main()
// {
// 	char *s = "4294965565655656565656565656565656565656";
// 	printf("ft = %d\n", ft_atoi(s));
// 	printf("norm = %d\n", atoi(s));
// }
