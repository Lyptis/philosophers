/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:36:30 by svanmeen          #+#    #+#             */
/*   Updated: 2023/06/13 13:00:47 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*life(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
}

void philos_init(t_philo **philos, t_data *info)
{
	t_philo		*curr;
	pthread_t	*tid;
	int			i;

	tid = malloc(sizeof(pthread_t) * info->nb_philo);
	i = 0;
	curr = *philos;
	info->start = gettime(0);
	while (i < info->nb_philo && curr)
	{
		if (i % 2 == 0)
			pthread_create(&(tid[i]), NULL, &life, curr);
		curr = curr->next;
		i++;
	}
	i = 0;
	curr = *philos;
	while (i < info->nb_philo && curr)
	{
		if (i % 2 != 0)
			pthread_create(&(tid[i]), NULL, &life, curr);
		curr = curr->next;
		i++;
	}
}
