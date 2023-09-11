/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelacou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:24:36 by ddelacou          #+#    #+#             */
/*   Updated: 2022/12/02 16:24:38 by ddelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_putchar_fd(char c, int fd, int *ptr, int *error);
int	ft_printf(const char *format, ...);
int	ft_formatfiltre(const char *format, va_list list, int i, int *error);
int	ft_putaddr(unsigned long addr, int *ptr, int *error);
int	ft_putnbr_fd(int n, int fd, int *ptr, int *error);
int	ft_putnbrhexamin(unsigned int n, int *ptr, int *error);
int	ft_putnbrhexamaj(unsigned int n, int *ptr, int *error);
int	ft_putstr_fd(const char *str, int fd, int *ptr, int *error);
int	ft_unsignedputnbr_fd(unsigned int n, int fd, int *ptr, int *error);

#endif
