/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:16:14 by nthimoni          #+#    #+#             */
/*   Updated: 2021/12/07 19:18:02 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printers.h"
#include "libft.h"
#include "buffer.h"
#include "parse_flags.h"

#include <stdio.h>
/*
static void	printf_flags(t_flags *flags)
{
	printf("%d\n", flags->minus);
	printf("%d\n", flags->zero);
	printf("%d\n", flags->diez);
	printf("%d\n", flags->space);
	printf("%d\n", flags->plus);
	printf("%d\n", flags->dot);
	printf("%d\n", flags->size);
	printf("%c\n", flags->type);
}
*/
static void init_flags(t_flags *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->diez = 0;
	flags->space = 0;
	flags->plus = 0;
	flags->dot = -1;
	flags->size = -1;
	flags->type = ' ';
}

static void dispatcher(t_flags *flags, va_list ap)
{
	if (flags->type == '%')
		write_buf("%", 1);
	else if (flags->type == 'c')
		print_c(va_arg(ap, int), flags);
	else if (flags->type == 's')
		print_s(va_arg(ap, char *), flags);
	else if (flags->type == 'p')
		print_p(va_arg(ap, void *), flags);
	else if (flags->type == 'd' || flags->type == 'i')
		print_di(va_arg(ap, int), flags);
	else if (flags->type == 'u')
		print_u(va_arg(ap, unsigned int), flags);
	else if (flags->type == 'x' || flags->type == 'X')
		print_xX(va_arg(ap, int), flags);
}

int	ft_printf(const char *s, ...)
{
	char	*flag_pos;
	t_flags	flags;
	va_list	ap;

	init_flags(&flags);
	va_start(ap, s);
	flag_pos = ft_strchr(s, '%');
	while (flag_pos)
	{
		write_buf(s, flag_pos - s);
		s = parse_flags(flag_pos, &flags);
		dispatcher(&flags, ap);
		flag_pos = ft_strchr(s, '%');
	}
	write_buf(s, ft_strlen(s));
	va_end(ap);
	return (write_buf(s, 0));
}
