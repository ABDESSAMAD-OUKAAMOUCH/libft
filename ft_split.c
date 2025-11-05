/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoukaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 20:04:32 by aoukaamo          #+#    #+#             */
/*   Updated: 2025/10/19 12:13:23 by aoukaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_memory(char **res, int l)
{
	int	i;

	i = 0;
	while (i < l)
	{
		free(res[i]);
		i++;
	}
	free(res);
}

static char	*copy_word(char const *s, int *index, char c)
{
	int		len;
	char	*res;
	int		i;
	int		j;

	len = 0;
	j = *index;
	while (s[j] && s[j] != c)
	{
		len++;
		j++;
	}
	res = malloc((len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = s[*index];
		i++;
		(*index)++;
	}
	res[i] = '\0';
	return (res);
}

static int	ft_check_allocation(char **res, int i)
{
	if (res[i] == NULL)
	{
		free_memory(res, i);
		return (0);
	}
	return (1);
}

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		index;
	int		i;

	if (s == NULL)
		return (NULL);
	res = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	index = 0;
	i = 0;
	while (s[index])
	{
		while (s[index] && s[index] == c)
			index++;
		if (s[index])
		{
			res[i] = copy_word(s, &index, c);
			if (!(ft_check_allocation(res, i)))
				return (NULL);
			i++;
		}
	}
	res[i] = NULL;
	return (res);
}
