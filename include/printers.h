/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:11:28 by nthimoni          #+#    #+#             */
/*   Updated: 2021/12/07 18:20:00 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTERS_H
# define PRINTERS_H

# include <stdarg.h>
# include "parse_flags.h"
# include <stdlib.h>

void	print_ui_base(unsigned long int val, const char *base);
size_t	ui_len(unsigned long int u, size_t base_len);
void	print_n_char(char c, int n);

void	print_s(const char *s, t_flags *flags);
void	print_c(unsigned char c, t_flags *flags);
void	print_u(unsigned int u, t_flags *flags);
void	print_di(int i, t_flags *flags);
void	print_p(void *p, t_flags *flags);
void	print_xX(int i, t_flags *flags);

#endif
