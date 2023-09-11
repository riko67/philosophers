/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelacou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:39:27 by ddelacou          #+#    #+#             */
/*   Updated: 2022/11/28 18:57:55 by ddelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(const char *str, int fd, int *ptr, int *error)
{
	if (!str)
	{
		ft_putstr_fd("(null)", fd, ptr, error);
		return (0);
	}
	while (*str != '\0')
	{
		ft_putchar_fd(*str, fd, ptr, error);
		str++;
	}
	return (0);
}
