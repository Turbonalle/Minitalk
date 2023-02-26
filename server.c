/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbagger <jbagger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 09:53:17 by jbagger           #+#    #+#             */
/*   Updated: 2023/02/21 13:01:40 by jbagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <signal.h>
#include "ft_printf/ft_printf.h"

static int message_length = 0;

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_join_str_with_char(char *s1, char c)
{
	char	*joined_str;
	size_t	i;
	size_t	len;

	if (s1)
		len = ft_strlen(s1) + 1;
	else
		len = 2;
	joined_str = (char *)malloc(sizeof(char) * (len));
	if (!joined_str)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		joined_str[i] = s1[i];
		i++;
	}
	joined_str[i++] = c;
	joined_str[i] = 0;
	free(s1);
	return (joined_str);
}

void	handler(int signal)
{
	static int				i = 0;
	static unsigned char	c = 0;
	static int				len = 0;
	static char				*str;
	int						j;

	if (message_length == 0 && i < 32)
	{
		i++;
		len <<= 1;
		len += (signal == SIGUSR1);
		if (i == 32)
		{
			message_length = len;
			i = 0;
		}
	}
	c <<= 1;
	if (signal == SIGUSR1)
		c++;
	i++;
	if (i == 8)
	{
		str = ft_join_str_with_char(str, c);
		if (!c)
		{
			ft_printf("%s\n", str);
			j = 0;
			while (str[j])
			{
				str[j] = 0;
				j++;
			}
			// free str!!!
		}
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	action;
	int					pid;

	action.sa_handler = handler;
	pid = getpid();
	ft_printf("pid = %d\n", pid);
	while (1)
	{
		sigaction(SIGUSR1, &action, NULL);
		sigaction(SIGUSR2, &action, NULL);
		pause();
	}
	return (0);
}
