/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainbuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblack-b <jblack-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 12:12:33 by jblack-b          #+#    #+#             */
/*   Updated: 2019/03/30 16:53:22 by jblack-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void ft_bzero(void *data, int size)
{
	int i; 

	i = 0;
	while	(i < size)
	{
		((char*) data)[i] = 0;
		i++;
	}
	
}

int main(int argc, char **argv)
{
	


	int curr = 0;
	int pointer = 0;
	char bytes[2048];
	char* operations = argv[1];
	int loop = 0;
	ft_bzero(bytes, 2048);
	while (operations[curr])
	{
		if (operations[curr] == '>')
			pointer++;
		else if (operations[curr] == '<')
			pointer--;
		else if (operations[curr] == '+')
			bytes[pointer]++;
		else if (operations[curr] == '-')
			bytes[pointer]--;
		else if (operations[curr] == '.')
			write(1, &bytes[pointer], 1);
		else if (operations[curr] == '[' && !bytes[pointer])
			{
				loop = 1;
				while(loop)
				{
					curr+=1;
					if (operations[curr] == '[')
						loop+=1;
					if (operations[curr] == ']')
						loop-=1;
				}

			}
		else if (operations[curr] == ']' && bytes[pointer])
			{
				loop = 1;
				while(loop)
				{
					curr-=1;
					if (operations[curr] == '[')
						loop-=1;
					if (operations[curr] == ']')
						loop+=1;
				}
			}
		curr++;
	}
	int i = 0;
	while (i < 2045)
	{
		printf("%d ", bytes[i++]);
	}
}