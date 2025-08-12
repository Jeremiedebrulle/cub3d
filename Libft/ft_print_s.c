/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lecartuy <lecartuy@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:51:52 by lecartuy          #+#    #+#             */
/*   Updated: 2024/12/09 12:16:30 by lecartuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_s(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!str)
	{
		tmp = "(null)";
		while (tmp[i])
		{
			if (ft_print_c(tmp[i]) == -1)
				return (-1);
			i++;
		}
	}
	else
	{
		while (str[i])
		{
			if (ft_print_c(str[i]) == -1)
				return (-1);
			i++;
		}
	}
	return (i);
}
