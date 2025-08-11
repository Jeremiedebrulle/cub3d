/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lecartuy <lecartuy@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:47:12 by lecartuy          #+#    #+#             */
/*   Updated: 2024/10/17 09:57:02 by lecartuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	start;
	size_t	end;
	size_t	trimmed_len;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	trimmed_len = end - start;
	result = malloc(sizeof(char) * (trimmed_len + 1));
	if (!result)
		return (NULL);
	ft_strlcpy(result, &s1[start], trimmed_len + 1);
	return (result);
}
// #include <stdio.h>

// int main(void)
// {
//     char *s1 = "            ";
//     char *set = " ";
//     char *trimmed;

//     trimmed = ft_strtrim(s1, set);
//     printf("Original: '%s'\n", s1);
//     printf("Trimmed: '%s'\n", trimmed);
//     free(trimmed);
//     return (0);
// }
