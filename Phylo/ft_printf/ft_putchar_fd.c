/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelacou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:12:29 by ddelacou          #+#    #+#             */
/*   Updated: 2022/11/16 20:12:31 by ddelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd, int *ptr, int *error)
{
	int	a;

	a = 0;
	if (*error != -1)
	{
		a = write(fd, &c, 1);
		(*ptr)++;
	}
	if (a == -1)
		*error = -1;
	return (0);
}
