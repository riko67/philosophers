/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsignedputnbr_fd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelacou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:33:28 by ddelacou          #+#    #+#             */
/*   Updated: 2022/12/02 16:33:36 by ddelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsignedputnbr_fd(unsigned int n, int fd, int *ptr, int *error)
{
	char	chaine[20];
	int		count;
	int		rest;

	count = 0;
	if (n == 0)
	{
		ft_putchar_fd('0', fd, ptr, error);
		return (0);
	}
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
