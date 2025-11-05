/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoukaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:21:30 by aoukaamo          #+#    #+#             */
/*   Updated: 2025/10/28 11:08:00 by aoukaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_dest;
	size_t	len_src;

	if (src == NULL)
		return (0);
	len_src = ft_strlen(src);
	if (size == 0)
		return (len_src);
	if (dst == NULL)
		return (0);
	len_dest = ft_strlen(dst);
	if (len_dest >= size)
		return (len_src + size);
	i = len_dest;
	j = 0;
	while (src[j] && (size - len_dest - 1) > j)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (len_dest + len_src);
}
