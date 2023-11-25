/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:00:53 by miturk            #+#    #+#             */
/*   Updated: 2023/11/25 14:45:11 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <signal.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

void recieve(int bit)
{
	static unsigned char temp;
	static int i;
	
	temp |= (bit == SIGUSR1);
	i++;
	if (i == 8)
	{
		ft_printf("%c", temp);
		i = 0;
		temp = 0;
	}
	else
		temp <<= 1;
}


int	main(int argc, char *argv[])
{
	__pid_t pid;

	pid = getpid();
	ft_printf("Process ID: %d\n", pid);
	printf("[-------------------------------------------------]\n");
	signal(SIGUSR2, recieve);
	signal(SIGUSR1, recieve);
	while (1)
		pause();
	ft_printf("\n");
	return (0);
}