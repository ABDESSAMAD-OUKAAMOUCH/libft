/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoukaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 18:22:55 by aoukaamo          #+#    #+#             */
/*   Updated: 2025/10/17 20:02:10 by aoukaamo         ###   ########.fr       */
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

static int	is_found(char ch, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*res;
	size_t	i;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	end = str_len(s1);
	while (s1[start] && is_found(s1[start], set))
		start++;
	while (end > start && is_found(s1[end - 1], set))
		end--;
	i = 0;
	res = malloc(end - start + 1);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (start < end)
	{
		res[i++] = s1[start++];
	}
	res[i] = '\0';
	return (res);
}
