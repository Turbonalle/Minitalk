/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbagger <jbagger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:02:23 by jbagger           #+#    #+#             */
/*   Updated: 2023/03/02 11:03:22 by jbagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>	// write()	usleep()
# include <signal.h>	// kill()
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"

typedef struct s_info
{
	char	*str;
	char	c;
	int		i;
	int		j;
	int		len;
	int		check;
}			t_info;

void	init_variables(t_info *info);

#endif