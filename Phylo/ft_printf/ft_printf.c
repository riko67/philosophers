/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelacou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:09:27 by ddelacou          #+#    #+#             */
/*   Updated: 2022/11/29 20:09:30 by ddelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		i;
	int		compteur;
	int		error;
	int		*ptr;

	va_start(list, format);
	ptr = &compteur;
	error = 0;
	compteur = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
			ft_putchar_fd(format[i++], 1, ptr, &error);
		if (format[i] == '%')
		{
			i++;
			compteur = compteur + ft_formatfiltre(format, list, i++, &error);
		}
	}
	va_end(list);
	if (error == -1)
		return (-1);
	return (compteur);
}
