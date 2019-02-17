/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_array_product.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblack-b <jblack-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 20:28:11 by jblack-b          #+#    #+#             */
/*   Updated: 2019/02/17 20:49:15 by jblack-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>


void		ft_swap_int(int *a, int *b)
{
	int temp;

	if (!a || !b)
		return ;
	temp = *a;
	*a = *b;
	*b = temp;
}


void		ft_arraysort(int *array, size_t length)
{
	size_t j;
	size_t k;

	j = 0;
	k = 0;
	if (array == NULL)
		return ;
	while (j < length)
	{
		while (k < length - 1)
		{
			if (array[k] > array[k + 1])
				ft_swap_int(&(array[k]), &(array[k + 1]));
			k++;
		}
		k = 0;
		j++;
	}
}

int main(void)
{
	int len = 5;
	int array[] = {1, 2, -20, -50, -1};
	if(len < 3)
		return (0);
	ft_arraysort(array, len);
	int x = array[len - 3];
	int y = array[len - 2];
	if ( array[0] < 0 && array[len-1] > 0 &&
		array[0] * array[1] > array[len-2] * array[len-3])
		{ x = array[0]; y = array[1]; }
	printf("%d * %d * %d = %d\n", x, y, array[len-1], x * y * array[len - 1]);
	return (0);
}
