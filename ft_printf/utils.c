/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:21:44 by lbrusa            #+#    #+#             */
/*   Updated: 2025/09/19 14:13:52 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * init_ops - Initialize the operations array with conversion functions.
 *
 * Arguments:
 *   ops: Array of function pointers for conversion operations.
 *
 * Returns:
 *   None.
 *
 * Description:
 *   Initializes the ops array with function pointers corresponding to
 *   printf conversion specifiers: %cspdiuxX%. The last element is an
 *   error handler for invalid conversions. Each function handles its
 *   respective conversion type with appropriate formatting.
 */
void	init_ops(t_ffunc *ops)
{
	ops[0] = pr_;
	ops[1] = pr_c;
	ops[2] = pr_s;
	ops[3] = pr_p;
	ops[4] = pr_i;
	ops[5] = pr_i;
	ops[6] = pr_u;
	ops[7] = pr_x;
	ops[8] = pr_xx;
	ops[9] = err_s;
}

/**
 * init_flags - Initialize and allocate a flags structure.
 *
 * Arguments:
 *   None.
 *
 * Returns:
 *   Pointer to the initialized flags structure, or NULL if allocation fails.
 *
 * Description:
 *   Allocates and initializes a t_flags structure with default values.
 *   Used for tracking formatting flags, width, precision, and padding
 *   in printf conversions. All flags are set to 0 and pad character to space.
 */

t_flags	*init_flags(void)
{
	t_flags	*flags;

	flags = malloc(sizeof(t_flags));
	if (flags == NULL)
		return (NULL);
	flags->minus = 0;
	flags->zero = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->dot = 0;
	flags->minw = 0;
	flags->padw = 0;
	flags->fw = 0;
	flags->len = 0;
	flags->prec = 0;
	flags->star = 0;
	flags->hash = 0;
	flags->hashhash = 0;
	flags->start = 0;
	flags->err = 0;
	flags->pad = ' ';
	flags->unsgned = 0;
	return (flags);
}

/**
 * width_prec_atoi - Convert string to integer for width/precision parsing.
 *
 * Arguments:
 *   p: Pointer to string pointer (updated during parsing).
 *
 * Returns:
 *   The converted integer value, or 0 if no digits found.
 *
 * Description:
 *   Variation of ft_atoi that skips non-digit characters and leading zeros.
 *   Updates the string pointer to point after the parsed number.
 *   Used for parsing width and precision in format specifiers.
 */
int	width_prec_atoi(char **p)
{
	int	n;
	int	sign;

	n = 0;
	sign = 1;
	if (**p == 0 || *p == 0 || p == 0)
		return (0);
	while ((!ft_isdigit(**p) || **p == '0') && **p != 0)
	{
		if (**p == '-')
			sign = -1;
		(*p)++;
	}
	while (ft_isdigit(**p))
		n = 10 * n + ((*(*p)++ - '0') * sign);
	return (n);
}

/**
 * safemalloc_and_set - Safely allocate and initialize a string buffer.
 *
 * Arguments:
 *   width: Size of buffer to allocate.
 *   c:     Character to fill the buffer with.
 *
 * Returns:
 *   Pointer to the allocated and initialized buffer, or NULL if allocation fails.
 *
 * Description:
 *   Allocates width+1 characters, fills with character 'c', and null-terminates.
 *   Used for creating padding buffers in printf formatting functions.
 */
char	*safemalloc_and_set(ssize_t width, int c)
{
	char	*s;

	s = malloc(sizeof(char) * (width + 1));
	if (!s)
		return (NULL);
	s = ft_memset((char *)s, c, width);
	s[width] = 0;
	return (s);
}

/**
 * get_width_and_precision - Parse width and precision from conversion string.
 *
 * Arguments:
 *   conv:  The conversion string to parse.
 *   width: Pointer to store the parsed width.
 *   prec:  Pointer to store the parsed precision.
 *
 * Returns:
 *   None.
 *
 * Description:
 *   Parses width and precision values from a conversion string.
 *   Handles cases with dot notation for precision. If only precision
 *   is specified (starts with '.'), width is set to 0.
 */
void	get_width_and_precision(char *conv, int *width, int *prec)
{
	if (*conv == '-')
		conv++;
	if (*conv == '.' && conv++)
	{
		*width = 0;
		*prec = width_prec_atoi(&conv);
	}
	else
	{
		*width = width_prec_atoi(&conv);
		if (*(conv) == '.')
			*prec = width_prec_atoi(&conv);
		else
			*prec = *width;
	}
}
