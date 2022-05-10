/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtorosya <vtorosya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:59:54 by vtorosya          #+#    #+#             */
/*   Updated: 2022/05/10 14:25:33 by vtorosya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	errors(int n)
{
	if (n == 1)
		printf("Arguments count must be 4 or 5\n");
	else if (n == 2)
		printf("Wrong number of philosophers\n");
	else if (n == 3)
		printf("Error: time to die\n");
	else if (n == 4)
		printf("Error: time to eat\n");
	else if (n == 5)
		printf("Error: time to sleep\n");
	else if (n == 6)
		printf("Wrong number of meals\n");
	else if (n == 7)
		printf("Error when initializing mutex\n");
	return (1);
}
