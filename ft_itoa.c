/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoukaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 09:11:23 by aoukaamo          #+#    #+#             */
/*   Updated: 2025/10/27 11:30:48 by aoukaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_len(long nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		len = 1;
	if (nbr < 0)
		nbr = -nbr;
	while (nbr > 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

static void	ft_convert(char *str, long nbr, int len)
{
	while (nbr > 0)
	{
		len--;
		str[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
}

char	*ft_itoa(int n)
{
	long	nbr;
	char	*str;
	int		len;

	nbr = n;
	len = ft_len(nbr);
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	if (nbr == 0)
		str[0] = '0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	ft_convert(str, nbr, len);
	return (str);
}
