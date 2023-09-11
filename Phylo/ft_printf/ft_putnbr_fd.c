/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelacou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:15:27 by ddelacou          #+#    #+#             */
/*   Updated: 2022/11/17 19:15:29 by ddelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_control(int nb, int fd, int *ptr, int *error)
{
	if (nb == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd, ptr, error);
		return (0);
	}
	if (nb == 0)
	{
		ft_putstr_fd("0", fd, ptr, error);
		return (0);
	}
	if (nb < 0)
	{
		ft_putstr_fd("-", fd, ptr, error);
		nb = -nb;
	}
	return (nb);
}

int	ft_putnbr_fd(int n, int fd, int *ptr, int *error)
{
	char	chaine[20];
	int		count;
	int		rest;
	int		control;

	count = 0;
	control = ft_control(n, fd, ptr, error);
	if (control == 0)
		return (0);
	n = control;
	while (n >= 1)
	{
		rest = n % 10;
		chaine[count] = rest + '0';
		count++;
		n = n / 10;
	}
	count--;
	while (count >= 0)
	{
		ft_putchar_fd(chaine[count], fd, ptr, error);
		count--;
	}
	return (0);
}
