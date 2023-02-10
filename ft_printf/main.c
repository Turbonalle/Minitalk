/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbagger <jbagger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:10:25 by jbagger           #+#    #+#             */
/*   Updated: 2022/12/18 11:18:23 by jbagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

int main()
{
	char c = 'X';
	char *s = "This is %d a string";
	int d = 123;
	unsigned int u = 1234567890;
	int result;
	int b = 217;

	printf("-------ft_printf:-------\n");
	result = ft_printf("c = '%c'\ns = '%s'\nd = '%d'\ni = '%i'\nx = '%x'\nX = '%X'\np = '%p'\nu = '%u'\n%%\n%", c, s, d, d, d, d, &s, u);
	printf("printed bytes = %d\n", result);
	//ft_printf("o = %o\nb = %b\n", d, b);

	printf("\n--------printf:--------\n");
	result = printf("c = '%c'\ns = '%s'\nd = '%d'\ni = '%i'\nx = '%x'\nX = '%X'\np = '%p'\nu = '%u'\n%%\n%", c, s, d, d, d, d, &s, u);
	printf("printed bytes = %d\n", result);
	//ft_printf("o = %o\nb = can't print binary numbers...\n", d, b);

	return (0);
}