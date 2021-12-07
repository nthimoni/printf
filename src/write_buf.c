/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_buf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 16:37:48 by nthimoni          #+#    #+#             */
/*   Updated: 2021/12/06 17:41:38 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "buffer.h"


static void	ft_subcat(char *dst, const char *src, size_t len)
{
	size_t	prev_len;
	size_t	i;

	prev_len = ft_strlen(dst);
	i = 0;
	while (i < len)
	{
		dst[prev_len + i] = src[i];
		++i;
	}
	dst[prev_len + i] = '\0';
}

static int	flush(char *buffer)
{
	int	wrote;

	wrote = write(1, buffer, ft_strlen(buffer));
	buffer[0] = '\0';
	return (wrote);
}

int	write_buf(const char *str, size_t len)
{
	static char		buffer[PRINTF_BUFFER + 1];
	size_t			wrote;
	size_t			to_copy;

	if (!len)
		return(flush(buffer));
	wrote = 0;
	if (len > PRINTF_BUFFER)
	{
		wrote += flush(buffer);
		return (wrote + write(1, str, len));
	}
	while (len > 0)
	{
		to_copy = PRINTF_BUFFER - ft_strlen(buffer);
		if (to_copy > len)
			to_copy = len;
		ft_subcat(buffer, str, to_copy);
		str += to_copy;
		len -= to_copy;
		if (ft_strlen(buffer) == PRINTF_BUFFER || ft_strchr(buffer, '\n'))
			wrote += flush(buffer);
	}
	return (wrote);
}
