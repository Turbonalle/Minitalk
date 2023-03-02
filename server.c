/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbagger <jbagger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 09:53:17 by jbagger           #+#    #+#             */
/*   Updated: 2023/03/02 11:01:07 by jbagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

void	init_variables(t_info *info)
{
	info->c = 0;
	info->check = 0;
	info->i = 0;
	info->j = 0;
	info->len = 0;
	info->str = NULL;
}

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
