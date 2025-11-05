/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoukaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 10:20:52 by aoukaamo          #+#    #+#             */
/*   Updated: 2025/10/27 10:53:07 by aoukaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_concatenate(char *res, char const *s, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		res[i] = s[i];
		i++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		len_s1;
	size_t		len_s2;
	char		*res;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	res = malloc(len_s1 + len_s2 + 1);
	if (res == NULL)
		return (NULL);
	ft_concatenate(res, s1, len_s1);
	ft_concatenate(res + len_s1, s2, len_s2);
	res[len_s1 + len_s2] = '\0';
	return (res);
}
