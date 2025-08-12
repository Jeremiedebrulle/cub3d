/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lecartuy <lecartuy@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:09:36 by lecartuy          #+#    #+#             */
/*   Updated: 2024/10/15 10:39:33 by lecartuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_strdup(const char *s1)
{
	char	*dest;

	dest = malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!dest)
		return (NULL);
	dest = ft_memcpy(dest, s1, (ft_strlen(s1) + 1));
	return (dest);
}
