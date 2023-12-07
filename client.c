/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:01:01 by miturk            #+#    #+#             */
/*   Updated: 2023/12/07 14:27:08 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

void	sending(int pid, unsigned char c)
{
	int				i;
	unsigned char	temp;

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
		usleep(420);
	}
}

int	main(int argc, char *argv[])
{
	int		id;
	char	*str;
	int		i;

	i = 0;
	if (argc != 3)
	{
		ft_printf("Invalid input\n");
		return (0);
	}
	id = ft_atoi(argv[1]);
	if (id < 0)
		return (0);
	str = argv[2];
	while (str[i])
	{
		sending(id, (unsigned char)str[i]);
		i++;
	}
	return (0);
}
