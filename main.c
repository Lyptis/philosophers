/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:43:11 by svanmeen          #+#    #+#             */
/*   Updated: 2023/03/30 15:51:19 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*sleeping(void *arg)
{

}

int	main(int argc, char **argv)
{
	pthread_t	tid[2];
	int			nb_threads;
	int			count;

	nb_threads = 2;
	count = 2;
	while (nb_threads != 0)
	{
		pthread_create(&(tid[nb_threads]), NULL, &sleeping, (void *)count);
	}

}
