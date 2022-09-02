/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepiment <hepiment@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:01:09 by hepiment          #+#    #+#             */
/*   Updated: 2022/08/16 19:05:42 by hepiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	ft_ptr(unsigned long address)
{
	if (!address)
	{
		return (ft_printf("(nil)") - 2);
	}
	else
	{
		ft_printf("0x");
		return (to_hex(address, 'x'));
	}
}
