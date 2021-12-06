/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:16:14 by nthimoni          #+#    #+#             */
/*   Updated: 2021/12/06 18:00:40 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printers.h"
#include "libft.h"
#include "buffer.h"
#include "parse_flags.h"

int	ft_printf(const char *s, ...)
{
	char	*flag_pos;
	va_list ap;

	va_start(ap, s);
	flag_pos = ft_strchr(s, '%');
	while (flag_pos)
	{
		write_buf(s, flag_pos - s);
		s = flag_pos + 1;
		flag_pos = ft_strchr(s, '%');
	}
	write_buf(s, ft_strlen(s));
	write_buf(s, 0);
	va_end(ap);
	return (0);
}
