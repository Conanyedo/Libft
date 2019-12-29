/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouddou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 23:30:12 by ybouddou          #+#    #+#             */
/*   Updated: 2019/12/08 15:20:56 by ybouddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		ft_intlen(int n, int sign)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (((len == 0) ? 1 : len) + sign);
}

static char		*ft_convert(int nlen, int sign, int n)
{
	char	*a;

	if (!(a = (char *)malloc((sizeof(char) * nlen + 1))))
		return (NULL);
	a[nlen] = '\0';
	while (--nlen >= sign)
	{
		a[nlen] = n % 10 + 48;
		n = n / 10;
	}
	if (nlen >= 0)
		a[nlen] = '-';
	return (a);
}

char			*ft_itoa(int n)
{
	int		nlen;
	char	*a;
	int		sign;

	nlen = 0;
	sign = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n = n * -1;
		sign = 1;
	}
	nlen = ft_intlen(n, sign);
	a = ft_convert(nlen, sign, n);
	return (a);
}

int		main()
{
	printf("itoa : %s", ft_itoa(3000000000));
}
