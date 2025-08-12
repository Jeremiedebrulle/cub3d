/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lecartuy <lecartuy@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:46:33 by lecartuy          #+#    #+#             */
/*   Updated: 2024/10/17 09:53:22 by lecartuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(long nb)
{
	size_t	len;

	len = 0;
	if (nb == 0)
		len++;
	if (nb < 0)
	{
		len++;
		nb *= -1;
	}
	while (nb != 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

static void	convert_char(char *tab, long nb, size_t i)
{
	if (nb < 0)
	{
		tab[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		tab[i--] = 48 + (nb % 10);
		nb /= 10;
	}
}

char	*ft_itoa(int n)
{
	long			nb;
	size_t			len;
	char			*str;

	nb = n;
	len = ft_count(nb);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len--] = '\0';
	if (nb == 0)
	{
		str[0] = '0';
		return (str);
	}
	convert_char(str, nb, len);
	return (str);
}

/*#include <stdio.h>
int	main(void)
{
	char	*result;

	result = ft_itoa(-2147483648);
	printf("%s\n", result);
	free(result);
}*/
