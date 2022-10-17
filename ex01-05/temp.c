/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:08:05 by gjacqual          #+#    #+#             */
/*   Updated: 2022/06/10 17:23:31 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#define STEP	20
#define UPPER	300
#define LOWER	0 

int	main(void)
{
	float	fahr;

	printf("Таблица температур по Фаренгейту и Цельсию\n\n");
	for (fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP)
		printf("%3.0f\t%6.1f\n", fahr, (5.0/9.0) * (fahr-32.0));
}