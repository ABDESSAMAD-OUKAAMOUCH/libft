/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoukaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 09:46:35 by aoukaamo          #+#    #+#             */
/*   Updated: 2025/10/22 18:47:35 by aoukaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*p;
	unsigned char	*s;
	size_t			t;

	if (size != 0 && nmemb > ((size_t) - 1) / size)
		return (NULL);
	t = nmemb * size;
	p = malloc(t);
	if (p == NULL)
		return (NULL);
	s = (unsigned char *)p;
	while (t--)
	{
		*s = 0;
		s++;
	}
	return (p);
}
