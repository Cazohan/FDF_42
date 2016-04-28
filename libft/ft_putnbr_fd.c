/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lherbelo <lherbelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 12:51:42 by lherbelo          #+#    #+#             */
/*   Updated: 2015/12/17 12:44:31 by lherbelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		nblen(int *len, int n)
{
	while (n != 0)
	{
		n /= 10;
		if (n != 0)
			*len *= 10;
	}
}

void			ft_putnbr_fd(int n, int fd)
{
	int			len;

	len = 1;
	if (n != -2147483648)
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n = -n;
		}
		nblen(&len, n);
		while (len >= 1)
		{
			ft_putchar_fd(48 + (n / len), fd);
			n = n % len;
			len = len / 10;
		}
	}
	else
		ft_putstr_fd("-2147483648", fd);
}
