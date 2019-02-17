/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblack-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 20:38:18 by jblack-b          #+#    #+#             */
/*   Updated: 2019/02/13 21:26:47 by jblack-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char *ft_itoa_base(int value, int base)
{
	char dict[] = "0123456789ABCDEF";
	char *result;
	int temp = value;
	int digits = 1;

	while (temp /= base)
		digits++;
	if (value < 0 &&  base == 10)
		digits++;
	result = malloc(sizeof(char) * digits + 1);
	result[digits] = '\0';
	if(value < 0 && base == 10)
		result[0]  = '-';
	while(digits--)
	{
		result[digits] = (value >= base ?  dict[value % base] : dict[value]);
		value /= base;
	}
	return (result);
}
