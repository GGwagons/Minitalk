/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:00:53 by miturk            #+#    #+#             */
/*   Updated: 2023/12/07 16:03:03 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"
#define SIZE 100000

void	ft_error(char *str)
{
	if (str == NULL)
		exit (1);
}

void	ft_recieve(int bit)
{
	static unsigned char	temp;
	static int				i;
	static char				*str;
	int						j;

	j = 0;
	str = malloc (sizeof(char) * SIZE);
	ft_error(str);
	temp |= (bit == SIGUSR1);
	i++;
	if (i == 8)
	{
		str[j++] = temp;
		i = 0;
		temp = 0;
	}
	else
		temp <<= 1;
	if (temp == '\0')
	{
		str[j] = '\0';
		ft_putstr_fd(str, 1);
		j = 0;
	}
	free(str);
}

int	main(int argc, char *argv[])
{
	__pid_t	pid;

	pid = getpid();
	ft_printf("Process ID: %d\n", pid);
	ft_printf("[-------------------------------------------------]\n");
	signal(SIGUSR2, ft_recieve);
	signal(SIGUSR1, ft_recieve);
	while (1)
		pause();
	ft_printf("\n");
	return (0);
}
