/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhshin <wonhshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:03:22 by wonhshin          #+#    #+#             */
/*   Updated: 2023/03/15 21:09:40 by wonhshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexlen(unsigned int n)
{
	int	len;
	int	notation;

	len = 0;
	notation = 16;
	if (n == 0)
		len++;
	while (n > 0)
	{
		n /= notation;
		len++;
	}
	return (len);
}

char	*ft_lowitoa(unsigned int n)
{
	char	*str;
	int		len;

	len = ft_hexlen(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	if (n == 0)
		str[0] = '0';
	str[len--] = '\0';
	while (n > 0)
	{
		str[len--] = "0123456789abcdef"[n % 16];
		n /= 16;
	}
	return (str);
}

char	*ft_upitoa(unsigned int n)
{
	char	*str;
	int		len;

	len = ft_hexlen(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	if (n == 0)
		str[0] = '0';
	str[len--] = '\0';
	while (n > 0)
	{
		str[len--] = "0123456789ABCDEF"[n % 16];
		n /= 16;
	}
	return (str);
}

int	ft_lowhex(unsigned int hex)
{
	char	*str;
	int		hex_len;

	str = ft_lowitoa(hex);
	hex_len = ft_strlen(str);
	ft_str(str);
	free(str);
	return (hex_len);
}

int	ft_uphex(unsigned int hex)
{
	char	*str;
	int		hex_len;

	str = ft_upitoa(hex);
	hex_len = ft_strlen(str);
	ft_str(str);
	free(str);
	return (hex_len);
}
