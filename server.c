/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbagger <jbagger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 09:53:17 by jbagger           #+#    #+#             */
/*   Updated: 2023/03/02 09:30:38 by jbagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <signal.h>
#include "libft/includes/libft.h"
#include "libft/includes/ft_printf.h"

//static unsigned int	message_length = 0;

//----TEST SEPARATING FUNCTION------------------------------------------ (WORKS)

typedef struct s_info
{
	char	*str;
	char	c;
	int		i;
	int		j;
	int		len;
	int		check;
}			t_info;

void	handle_length(int signal, t_info *info)
{
	info->len += (signal == SIGUSR1) << info->i;
	(info->i)++;
	if (info->i == 32)
	{
		info->i = 0;
		info->str = malloc(sizeof(char) * (info->len + 1));
		info->str[info->len] = '\0';
		info->check = 1;
	}
}

void	handle_message(int signal, t_info *info)
{
	info->c <<= 1;
	if (signal == SIGUSR1)
		info->c++;
	info->i++;
	if (info->i == 8)
	{
		info->str[info->j] = info->c;
		info->j++;
		if (!info->c)
		{
			ft_printf("%s\n", info->str);
			info->j = 0;
			while (info->str[info->j])
			{
				info->str[info->j] = 0;
				info->j++;
			}
			info->j = 0;
			info->len = 0;
			info->check = 0;
		}
		info->i = 0;
		info->c = 0;
	}
}

void	init_variables(t_info *info)
{
	info->c = 0;
	info->check = 0;
	info->i = 0;
	info->j = 0;
	info->len = 0;
	info->str = NULL;
}

void	handler(int signal)
{
	static t_info	info;
	static int		check = 0;

	if (check == 0)
	{
		init_variables(&info);
		check = 1;
	}
	if (info.check == 0 && info.i < 32)
		handle_length(signal, &info);
	else
		handle_message(signal, &info);
}

//----TEST WITHOUT GLOBAL----------------------------------------------- (WORKS)

// void	handler(int signal)
// {
// 	static int				i = 0;
// 	static unsigned char	c = 0;
// 	static char				*str = NULL;
// 	static int				j = 0;
// 	static unsigned int		len = 0;
// 	static int				check = 0;

// 	if (check == 0 && i < 32)
// 	{
// 		len += (signal == SIGUSR1) << i;
// 		i++;
// 		if (i == 32)
// 		{
// 			len = 0;
// 			i = 0;
// 			str = malloc(sizeof(char) * (len + 1));
// 			str[len] = '\0';
// 			check = 1;
// 		}
// 	}
// 	else
// 	{
// 		c <<= 1;
// 		if (signal == SIGUSR1)
// 			c++;
// 		i++;
// 		if (i == 8)
// 		{
// 			str[j] = c;
// 			j++;
// 			if (!c)
// 			{
// 				ft_printf("%s\n", str);
// 				j = 0;
// 				while (str[j])
// 				{
// 					str[j] = 0;
// 					j++;
// 				}
// 				j = 0;
// 				//free(str);
// 				len = 0;
// 				check = 0;
// 			}
// 			i = 0;
// 			c = 0;
// 		}
// 	}
// }

//----ACTUAL--------------------------------------------------------------------

// void	handler(int signal)
// {
// 	static int				i = 0;
// 	static unsigned char	c = 0;
// 	static char				*str = NULL;
// 	static int				j = 0;
// 	static unsigned int		len = 0;

// 	if (message_length == 0 && i < 32)
// 	{
// 		len += (signal == SIGUSR1) << i;
// 		i++;
// 		if (i == 32)
// 		{
// 			message_length = len;
// 			len = 0;
// 			i = 0;
// 			str = malloc(sizeof(char) * (message_length + 1));
// 			str[message_length] = '\0';
// 		}
// 	}
// 	else
// 	{
// 		c <<= 1;
// 		if (signal == SIGUSR1)
// 			c++;
// 		i++;
// 		if (i == 8)
// 		{
// 			str[j] = c;
// 			j++;
// 			if (!c)
// 			{
// 				ft_printf("%s\n", str);
// 				j = 0;
// 				while (str[j])
// 				{
// 					str[j] = 0;
// 					j++;
// 				}
// 				j = 0;
// 				//free(str);
// 				message_length = 0;
// 			}
// 			i = 0;
// 			c = 0;
// 		}
// 	}
// }

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
