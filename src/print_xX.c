/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xX.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:34:50 by nthimoni          #+#    #+#             */
/*   Updated: 2021/12/07 17:43:46 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_flags.h"
#include "buffer.h"
#include "bases.h"
#include "printers.h"

void	print_xX(int i, t_flags *flags)
{	
	size_t			len;

	len = ui_len((unsigned int)i, 16);
	if (flags->diez)
		len += 2;
	reg_dot(flags, len);
	if (!flags->minus && !flags->zero)
		print_n_char(' ', flags->size - len, flags->dot - len);
	if (!flags->minus && flags->zero)
		print_n_char('0', flags->size - len, 0);
	if (flags->diez && flags->type == 'x')
		write_buf("0x", 2);
	if (flags->diez && flags->type == 'X')
		write_buf("0X", 2);
	if (flags->type == 'x')
		print_ui_base((unsigned int)i, BASE_16_LOW);
	if (flags->type == 'X')
		print_ui_base((unsigned int)i, BASE_16_UP);
	if (flags->minus)
		print_n_char(' ', flags->size - len, 0);
}
