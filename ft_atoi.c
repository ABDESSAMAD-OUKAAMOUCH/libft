/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoukaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:43:57 by aoukaamo          #+#    #+#             */
/*   Updated: 2025/11/05 09:44:53 by aoukaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	remove_space(const char *nptr)
{
	int	i;

	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int					i;
	unsigned long long	res;
	int					sign;

	if (nptr == NULL)
		return (0);
	i = remove_space(nptr);
	res = 0;
	sign = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		if (sign == 1 && res > 9223372036854775807ULL)
			return (-1);
		if (sign == -1 && res > 9223372036854775808ULL)
			return (0);
		i++;
	}
	return ((int)(res * sign));
}
