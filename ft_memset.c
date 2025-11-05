/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoukaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 09:39:43 by aoukaamo          #+#    #+#             */
/*   Updated: 2025/10/28 11:06:28 by aoukaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*b;

	if (s == NULL)
		return (NULL);
	b = (unsigned char *)s;
	while (n > 0)
	{
		*b = (unsigned char)c;
		b++;
		n--;
	}
	return (s);
}
