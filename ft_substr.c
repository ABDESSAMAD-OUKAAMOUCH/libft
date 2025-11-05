/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoukaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:56:52 by aoukaamo          #+#    #+#             */
/*   Updated: 2025/10/17 18:21:54 by aoukaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	str_len(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static void	copy_str(size_t len, unsigned int start, char *str, char const *s)
{
	size_t	i;

	i = 0;
	while (i < len && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	ls;

	if (s == NULL)
		return (NULL);
	ls = str_len(s);
	if (start >= ls)
	{
		str = malloc(1);
		if (str == NULL)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if (len > ls - start)
		len = ls - start;
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	copy_str(len, start, str, s);
	return (str);
}
