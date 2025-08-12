/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lecartuy <lecartuy@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:10:55 by lecartuy          #+#    #+#             */
/*   Updated: 2024/10/17 09:03:55 by lecartuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	size_needle;

	size_needle = ft_strlen(needle);
	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len >= size_needle)
	{
		if (!ft_strncmp(haystack, needle, size_needle))
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}

/*#include <stdio.h>

int	main(void)
{
	const char *haystack = "Hello, World!";
	const char *needle = "World";
	size_t len = 14;
	char *result;

	result = ft_strnstr(haystack, needle, len);
	if (result)
		printf("found: '%s'\n", result);
	else
		printf("'%s' not found within the first %zu characters of '%s'.\n",
			needle, len, haystack);

	return (0);
}*/
