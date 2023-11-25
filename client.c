/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:01:01 by miturk            #+#    #+#             */
/*   Updated: 2023/11/25 15:28:18 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <signal.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

void sending(int pid, unsigned char c)
{
	int i;
	unsigned char temp;
	i = 8;
	temp = c;
	while (i > 0)
	{
		i--;
		temp = c >> i;
		if (temp % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(42);
	}
	
}

int	main(int argc, char *argv[])
{
	int id;
	char *str;
	int i;

	id = ft_atoi(argv[1]);
	str = argv[2];
	
	if (argc != 3)
	{
		printf("Invalid input\n");
		return (0);
	}
	while (str[i] != '\0')
	{
		sending(id, (unsigned char)str[i]);
		i++;
	}
	sending(id, '\n');
	return (0);
}