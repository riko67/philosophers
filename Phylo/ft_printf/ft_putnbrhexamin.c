/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrhexamin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelacou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:08:17 by ddelacou          #+#    #+#             */
/*   Updated: 2022/12/06 15:08:23 by ddelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbrhexamin(unsigned int n, int *ptr, int *error)
{
	char	*chaine;
	int		count;

	count = n % 16;
	chaine = "0123456789abcdef";
	if (n >= 16)
	{
		if (ft_putnbrhexamin(n / 16, ptr, error))
			return (-1);
		count = n % 16;
		n = n / 16;
	}
	ft_putchar_fd(chaine[count], 1, ptr, error);
	return (0);
}
