/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lecartuy <lecartuy@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:46:58 by lecartuy          #+#    #+#             */
/*   Updated: 2024/10/17 09:11:58 by lecartuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_tab(char **tab, size_t i)
{
	while (i > 0)
	{
		free(tab[i - 1]);
		i--;
	}
	free(tab);
}

static size_t	count_words(const char *str, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			count++;
			while ((str[i] != c) && (str[i] != '\0'))
				i++;
			if (str[i] == '\0')
				return (count);
		}
		i++;
	}
	return (count);
}

static int	alloc_cpy_strs(char **tab, const char *str, size_t count,
		size_t index)
{
	tab[index] = malloc(sizeof(char) * (count + 1));
	if (!tab[index])
		return (0);
	ft_strlcpy(tab[index], str, count + 1);
	return (1);
}

static char	**make_strs(char **tab, const char *str, char c)
{
	size_t	i;
	size_t	count;
	size_t	index;

	i = 0;
	index = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		count = 0;
		while (str[i + count] && str[i + count] != c)
			count++;
		if (count > 0)
		{
			if (!alloc_cpy_strs(tab, &str[i], count, index))
			{
				free_tab(tab, index);
				return (NULL);
			}
			index++;
			i += count;
		}
	}
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	size_t	strs;
	char	**tab;

	if (!s)
		return (NULL);
	strs = count_words(s, c);
	tab = malloc(sizeof(char *) * (strs + 1));
	if (!tab)
		return (NULL);
	tab[strs] = NULL;
	return (make_strs(tab, s, c));
}

/*#include <stdio.h>

int	main(void)
{
	char **result;
	char *string = "Hello,,42,,world!";
	char delimiter = ',';
	int i = 0;

	result = ft_split(string, delimiter);
	while (result[i])
	{
		printf("%s\n", result[i]);
		i++;
	}
	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);

	return (0);
}*/