/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 13:34:02 by hstiv             #+#    #+#             */
/*   Updated: 2019/01/13 14:55:19 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n)
		return (0);
	while (n && *s1++ == *s2++ && *(s1 - 1))
		n--;
	return (*(unsigned char*)(s1 - 1) - *(unsigned char*)(s2 - 1));
}
