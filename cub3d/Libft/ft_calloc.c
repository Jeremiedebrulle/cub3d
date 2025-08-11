/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lecartuy <lecartuy@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:04:25 by lecartuy          #+#    #+#             */
/*   Updated: 2024/10/17 09:57:22 by lecartuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	length;
	void	*dest;

	length = count * size;
	if (size && length / size != count)
		return (NULL);
	dest = malloc(length);
	if (!dest)
		return (NULL);
	ft_bzero(dest, length);
	return (dest);
}

/*#include <stdio.h> 

int main(void)
{
    int *str;
    size_t count = 5;
    size_t size = sizeof(int);
    size_t i = 0;

    str = (int *)ft_calloc(count, size);
    
    while (i < count)
    {
        printf("arr[%zu] = %d\n", i, str[i]);
        i++;
    }
    free(str);
    return (0);
}*/
