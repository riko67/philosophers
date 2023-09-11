/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatfiltre.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelacou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:27:31 by ddelacou          #+#    #+#             */
/*   Updated: 2022/11/30 18:27:32 by ddelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formatfiltre(const char *format, va_list list, int i, int *error)
{
	int	*ptr;
	int	compteur;

	compteur = 0;
	ptr = &compteur;
	if (format[i] == 'c')
		ft_putchar_fd((char)va_arg(list, char *), 1, ptr, error);
	else if (format[i] == 's')
		ft_putstr_fd(va_arg(list, char *), 1, ptr, error);
	else if (format[i] == 'd' || format[i] == 'i')
		ft_putnbr_fd(va_arg(list, int), 1, ptr, error);
	else if (format[i] == 'u')
		ft_unsignedputnbr_fd(va_arg(list, unsigned int), 1, ptr, error);
	else if (format[i] == 'x')
		ft_putnbrhexamin(va_arg(list, int), ptr, error);
	else if (format[i] == 'X')
		ft_putnbrhexamaj(va_arg(list, int), ptr, error);
	else if (format[i] == '%')
		ft_putstr_fd("%", 1, ptr, error);
	else if (format[i] == 'p')
	{
		ft_putstr_fd("0x", 1, ptr, error);
		ft_putaddr(va_arg(list, unsigned long), ptr, error);
	}
	return (compteur);
}
