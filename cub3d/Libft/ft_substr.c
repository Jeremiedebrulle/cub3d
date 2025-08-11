/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lecartuy <lecartuy@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:47:15 by lecartuy          #+#    #+#             */
/*   Updated: 2024/10/17 11:04:25 by lecartuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	result = (char *)ft_calloc(len + 1, sizeof(char));
	if (!result)
		return (NULL);
	ft_memcpy(result, s + start, len);
	return (result);
}

/*#include <stdio.h>

int	main()
{
	const char *s = "Hello, World!";
    unsigned int start = 7; 
    size_t len = 5;
    char *sub;

    sub = ft_substr(s, start, len);
    printf("%s\n", sub);
    free(sub);
}*/