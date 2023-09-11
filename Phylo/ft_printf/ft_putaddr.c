/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelacou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:44:42 by ddelacou          #+#    #+#             */
/*   Updated: 2022/12/01 18:44:43 by ddelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putaddr(unsigned long addr, int *ptr, int *error)
{
	char	*chaine;
	int		count;

	count = addr % 16;
	chaine = "0123456789abcdef";
	if (addr >= 16)
	{
		if (ft_putaddr(addr / 16, ptr, error))
			return (-1);
		count = addr % 16;
		addr = addr / 16;
	}
	ft_putchar_fd(chaine[count], 1, ptr, error);
	return (0);
}
